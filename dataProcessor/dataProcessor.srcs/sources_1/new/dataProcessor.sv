`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/05/2022 11:42:39 PM
// Design Name: 
// Module Name: dataProcessor
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module dataProcessor #(
    parameter D_WIDTH               = 16,
    parameter B_WIDTH               = 16

    )(
    input   signed [D_WIDTH-1:0]        s_axis_data_tdata,     // 16 bitlik ADC datasi...
    output                              s_axis_data_tready,    // Su anda kullanilmiyor.
    input                               s_axis_data_tvalid,    // ADC datasinin valid sinyali.
    
    input   [32-1:0]                    ddc_config,            // DownConvertion Rate. 20 kHz cozunurluk
    input   [2-1:0]                     filter_config,         // 0 ise 3 kHz, 1 ise 6 kHz, 2 ise 9 kHz, 3 ise 12 kHz
    input                               config_valid,          // 1 ise config datalari okunur.
    
    input                               a_clk,
    input                               a_resetn,
    
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r,   // I data
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i,   // Q data
    output  logic                       m_axis_data_tvalid     // Output valid
        
    );

// STAGE_CONF: 
localparam [32-1:0] CONF_MULTIPLIER = 32'd3518437209;   // (1/1000) Q32.45
localparam [16-1:0] DDC1_RESOLUTION = 10000;
localparam          TRUNCATION_NUM  = 45;

reg [32-1:0]    ddc_config_s=0;
always@(posedge a_clk)
begin
    if(!a_resetn)
    begin
        ddc_config_s    <= ddc_config;
    end
    else if(config_valid)
    begin
        ddc_config_s    <= ddc_config;
    end
end

reg [32 + 32 - 1 :0]    ddc_config_multiplier_s=0, ddc_config_multiplier=0;
reg [16-1:0]            ddc_config_1_pre=0, ddc_config_1=0,ddc_config_2=0;
reg [32-1:0]            ddc_config_1_val;
always@(posedge a_clk)
begin
    ddc_config_multiplier   <= ddc_config_s * CONF_MULTIPLIER;
    ddc_config_multiplier_s <= ddc_config_multiplier;   
    ddc_config_1_pre        <= ddc_config_multiplier_s >>> TRUNCATION_NUM;
    
    ddc_config_1_val        <= ddc_config_1_pre * DDC1_RESOLUTION;
    
    ddc_config_1            <= ddc_config_1_pre;
    ddc_config_2            <= ddc_config_s - ddc_config_1_val;
end


    
//---- STAGE0:
// Bu aşamada gelen sinyal DDC modülü ile downConvert edilir. Downconvertion değeri ddc_config parametresi ile belirlenir.
// ddc_config parametresinin çözünürlüğü 20 kHz olarak ayarlanmıştır.
// Örnek olarak 100 MHz ile gelen sinyalin 20 MHz downconvert etmek istiyorsanız ddc_config değeri 20 MHz / 20 kHz = 1000 girilmelidir.
logic   signed  [D_WIDTH-1:0]     s_axis_data_downconverted_s1_r, s_axis_data_downconverted_s1_i; 
logic                             s_axis_data_downconverted_s1_v;
digitalDownConverter #(
    .D_WIDTH(D_WIDTH),            
    .B_WIDTH(B_WIDTH),
    .INPUT_TYPE(0)                  
)
DDC1
(
    .s_axis_data_tdata_r(s_axis_data_tdata),
    .s_axis_data_tdata_i(),
    .s_axis_data_tready(s_axis_data_tready),
    .s_axis_data_tvalid(s_axis_data_tvalid),
    
    .config_data(ddc_config_1),
    
    .a_clk(a_clk),
    .a_resetn(a_resetn),
    
    .m_axis_data_tdata_r(s_axis_data_downconverted_s1_r),
    .m_axis_data_tdata_i(s_axis_data_downconverted_s1_i),
    .m_axis_data_tvalid(s_axis_data_downconverted_s1_v)
    );
    
    
// ---- STAGE1:  
// Bu aşamada DDC bloğundan çıkan sinyal birinci filtreden geçirilir. Bu filtre ile data rate 1/64 oranında düşürülür.
// Örnek olarak 100 MHz ile gelen sinyal 100 / 64 MHz data rate e düşürülür.
// Buradaki filtre coefficient dosyası proje içindeki matlab aldtında firCoefficients.coe dir.
// Bu dosyayı lowPassStage1 IP'sine okutabilirsiniz.
// Filtre değiştirilmek isteniyorsa matlab/firFilter.m scriptindeki Fpass,Fcut değerleri ile oynanarak yeni dosya üretilir.
// Yeni dosyanın etki etmesi için IP tekrar açılmalı ve load coe file yapıldıktan sonra tekrar generate edilmelidir.
// Burada data rate 1/64 oranında indirildiği için decimation 64 olarak seçilmelidir.  
logic   signed  [D_WIDTH+8-1:0]   s_axis_data_filtered_s1_r  , s_axis_data_filtered_s1_i; 
logic                             s_axis_data_filtered_s1_r_v, s_axis_data_filtered_s1_i_v;
logic                             s_axis_data_tready_s1_r,s_axis_data_tready_s1_i;

lowPassStage1 fir_stage1_r (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                              // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s1_v),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s1_r),  // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s1_r),    // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s1_r_v),  // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s1_r)    // output wire [15 : 0] m_axis_data_tdata
);


lowPassStage1 fir_stage1_i (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                              // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s1_v),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s1_i),  // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s1_i),    // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s1_i_v),  // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s1_i)    // output wire [15 : 0] m_axis_data_tdata
);  



// ---- STAGE2: 
// İkinci aşamada ise sinyal tekrar 1/64 oranında seyreltilir.
// Dolayısıyla nihai data rate 100/64/64 = 24.4 kHz olarak çıkar.
// Burada kullanılan IP lowPassStage2 IP'sidir. Birinci aşamadan farklı olarak buradaki filtre coefficientları seçilebilir olarak tasarlanmıştır.
// Filtrede 4 adet LP coefficient vardır. (3,6,9,12) kHz.
// Filtrenin coe dosyası matlab/firFilterS2.m dosyası ile üretilir.
// Filtre değiştirilmek isteniyorsa matlab/firFilter.m scriptindeki Fpass,Fcut değerleri ile oynanarak yeni dosya üretilir.
// Yeni dosyanın etki etmesi için IP tekrar açılmalı ve load coe file yapıldıktan sonra tekrar generate edilmelidir.
// Burada data rate 1/64 oranında indirildiği için decimation 64 olarak seçilmelidir.  

logic   signed  [D_WIDTH+8-1:0]   s_axis_data_filtered_s2_r  , s_axis_data_filtered_s2_i; 
logic                             s_axis_data_filtered_s2_r_v, s_axis_data_filtered_s2_i_v;
logic                             s_axis_data_tready_s2_r,s_axis_data_tready_s2_i;
lowPassStage2 fir_stage2_r (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                                          // input wire aclk
  .s_axis_data_tvalid(s_axis_data_filtered_s1_r_v),     // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s2_r),         // output wire s_axis_data_tready
  .s_axis_data_tdata($signed(s_axis_data_filtered_s1_r[D_WIDTH-1:0])),        // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s2_r_v),     // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s2_r)         // output wire [15 : 0] m_axis_data_tdata
);

lowPassStage2 fir_stage2_i (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                                          // input wire aclk
  .s_axis_data_tvalid(s_axis_data_filtered_s1_i_v),     // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s2_i),         // output wire s_axis_data_tready
  .s_axis_data_tdata($signed(s_axis_data_filtered_s1_i[D_WIDTH-1:0])),        // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s2_i_v),     // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s2_i)         // output wire [15 : 0] m_axis_data_tdata
);

logic   signed  [D_WIDTH-1:0]     s_axis_data_downconverted_s2_r, s_axis_data_downconverted_s2_i; 
logic                             s_axis_data_downconverted_s2_v;
digitalDownConverter #(
    .D_WIDTH(D_WIDTH),            
    .B_WIDTH(B_WIDTH),
    .INPUT_TYPE(1)                  
)
DDC2
(
    .s_axis_data_tdata_r($signed(s_axis_data_filtered_s2_r[D_WIDTH-1:0])),
    .s_axis_data_tdata_i($signed(s_axis_data_filtered_s2_i[D_WIDTH-1:0])),
    .s_axis_data_tready(),
    .s_axis_data_tvalid(s_axis_data_filtered_s2_r_v),
    
    .config_data(ddc_config_2),
    
    .a_clk(a_clk),
    .a_resetn(a_resetn),
    
    .m_axis_data_tdata_r(s_axis_data_downconverted_s2_r),
    .m_axis_data_tdata_i(s_axis_data_downconverted_s2_i),
    .m_axis_data_tvalid(s_axis_data_downconverted_s2_v)
    );


// ---- STAGE3: 
// ---------------------------------------------------------------------------------------------------

logic [8-1:0]   s_axis_config_tdata=0;
logic           s_axis_config_tvalid=0;
logic           send_config=0;
logic           s_axis_config_r_tready,s_axis_config_i_tready;
logic           config_valid_s=0;
logic [16-1:0]  filter_config_s;
always@(posedge a_clk)
begin
    if(!a_resetn)
    begin
        config_valid_s      <= 0;
        filter_config_s     <= 0;
        s_axis_config_tdata <= 0;
    end
    else
    begin
        config_valid_s          <= config_valid;
        filter_config_s         <= filter_config;
        s_axis_config_tdata     <= filter_config_s[8-1:0];
        s_axis_config_tvalid    <= send_config;
        if(config_valid_s)
            send_config <= 1'b1;
        else if(send_config && s_axis_config_r_tready && s_axis_config_i_tready)
            send_config <= 1'b0;
    end

end

logic   signed  [D_WIDTH-1:0]     s_axis_data_filtered_s3_r  , s_axis_data_filtered_s3_i; 
logic                             s_axis_data_filtered_s3_r_v, s_axis_data_filtered_s3_i_v;
logic                             s_axis_data_tready_s3_r,s_axis_data_tready_s3_i;

lowPassStage3 fir_stage3_r (
  .aresetn(a_resetn),                        // input wire aresetn
  .aclk(a_clk),                                  // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s2_v),      // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s3_r),      // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s2_r),        // input wire [15 : 0] s_axis_data_tdata
  .s_axis_config_tvalid(s_axis_config_tvalid),  // input wire s_axis_config_tvalid
  .s_axis_config_tready(s_axis_config_r_tready),  // output wire s_axis_config_tready
  .s_axis_config_tdata(s_axis_config_tdata),    // input wire [7 : 0] s_axis_config_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s3_r_v),      // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s3_r)        // output wire [15 : 0] m_axis_data_tdata
);

lowPassStage3 fir_stage3_i (
  .aresetn(a_resetn),                        // input wire aresetn
  .aclk(a_clk),                                  // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s2_v),      // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s3_i),      // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s2_i),        // input wire [15 : 0] s_axis_data_tdata
  .s_axis_config_tvalid(s_axis_config_tvalid),  // input wire s_axis_config_tvalid
  .s_axis_config_tready(s_axis_config_i_tready),  // output wire s_axis_config_tready
  .s_axis_config_tdata(s_axis_config_tdata),    // input wire [7 : 0] s_axis_config_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s3_i_v),      // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s3_i)        // output wire [15 : 0] m_axis_data_tdata
);

//----- OUTPUT ASSIGNMENT-------------------------------------------------------------------------
// Nihai sinyal output portlarına burada atanır.
// m_axis_data_tdata_r : I data
// m_axis_data_tdata_i : Q data
// m_axis_data_tvalid  : Valid
// veri hızı 100 MHz/64/64 = 22.4 kHz
always@(posedge a_clk)
begin
    m_axis_data_tdata_r <= s_axis_data_filtered_s3_r;
    m_axis_data_tdata_i <= s_axis_data_filtered_s3_i;
    m_axis_data_tvalid  <= s_axis_data_filtered_s3_r_v;

end
        
endmodule

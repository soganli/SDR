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
    
    input   [32-1:0]                    ddc_config,            // DownConvertion Rate. 1 Hz Cozunurluk. DownConvert edılmek ıstenen frekans Hz cınsınden gırılmelı. Ornek 10 MHz = 10000000.
    input   [2-1:0]                     filter_config,         // 0 ise 3 kHz, 1 ise 6 kHz, 2 ise 9 kHz, 3 ise 12 kHz
    input                               config_valid,          // 1 ise config datalari okunur. Opsiyoneldir. Kullanilmaz ise confıg datasi degistigi zaman gecerli olur.
    
    input                               a_clk,
    input                               a_resetn,
    
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r,   // I data
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i,   // Q data
    output  logic                       m_axis_data_tvalid     // Output valid
        
    );

// STAGE_CONFIG: --------------------------------------------------------------------------------------------------
// DDC ve Filtre Conf verileri burada okunur.
localparam [32-1:0] CONF_MULTIPLIER = 32'd3518437209;   // (1/1000) Q32.45
localparam [16-1:0] DDC1_RESOLUTION = 10000;
localparam          TRUNCATION_NUM  = 45;

reg [32-1:0]    ddc_config_s=0;
reg [32-1:0]    ddc_config_reg [4-1:0];
always@(posedge a_clk)
begin
    if(!a_resetn)
    begin
        ddc_config_s    <= 0;
    end
    else// if(config_valid)
    begin
        ddc_config_s        <= ddc_config;
        ddc_config_reg[0]   <= ddc_config_s;
        ddc_config_reg[1]   <= ddc_config_reg[0];
        ddc_config_reg[2]   <= ddc_config_reg[1];
        ddc_config_reg[3]   <= ddc_config_reg[2];
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
    ddc_config_2            <= ddc_config_reg[3] - ddc_config_1_val;
end

logic [8-1:0]   s_axis_config_tdata=0;
logic           s_axis_config_tvalid=0;
logic           send_config=0;
logic           s_axis_config_r_tready,s_axis_config_i_tready;
logic           config_valid_s=0,config_valid_ss=0;
logic [2-1:0]   filter_config_s,filter_config_ss;
always@(posedge a_clk)
begin
    if(!a_resetn)
    begin
        config_valid_s      <= 0;
        config_valid_ss     <= 0;
        filter_config_s     <= 0;
        filter_config_ss    <= 0;
        s_axis_config_tdata <= 0;
    end
    else
    begin
        config_valid_s          <= config_valid;
        filter_config_s         <= filter_config;
        
        config_valid_ss         <= config_valid_s;
        filter_config_ss        <= filter_config_s;
        
        s_axis_config_tdata     <= {6'd0,filter_config_ss};
        s_axis_config_tvalid    <= send_config;
        if(config_valid_ss || (filter_config_ss != filter_config_s))
            send_config <= 1'b1;
        else if(send_config && s_axis_config_r_tready && s_axis_config_i_tready)
            send_config <= 1'b0;
    end

end

    
//---- STAGE0:
// Bu asamada gelen sinyal DDC modulu ile downConvert edilir. Downconvertion değeri ddc_config_1 parametresi ile belirlenir.
// ddc_config_1 parametresinin cozunurlugu 10 kHz.
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
// Bu asamada DDC blogundan cikan sinyal birinci filtreden gecirilir. Bu filtre ile data rate 1/64 oranında dusurulur.
// Ornek olarak 100 MHz ile gelen sinyal 100 / 64 MHz data rate e dusurulur.
// Buradaki filtre coefficient dosyası proje icindeki matlab aldtında firCoefficientsS1.coe dir.
// Bu dosyayı lowPassStage1 IP'sine okutabilirsiniz.
// Filtre degistirilmek isteniyorsa matlab/firFilterS1.m scriptindeki Fpass,Fcut degerleri ile oynanarak yeni dosya uretilir.
// Yeni dosyanın etki etmesi için IP tekrar acilmali ve load coe file yapildiktan sonra tekrar generate edilmelidir.
// Burada data rate 1/64 oranında indirildigi için decimation 64 olarak secilmelidir.  
logic   signed  [D_WIDTH+8-1:0]   s_axis_data_filtered_s1_r  , s_axis_data_filtered_s1_i; 
logic                             s_axis_data_filtered_s1_r_v, s_axis_data_filtered_s1_i_v;
logic                             s_axis_data_tready_s1_r,s_axis_data_tready_s1_i;

lowPassStage1 fir_stage1_r (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                                         // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s1_v),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s1_r),         // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s1_r),   // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s1_r_v),     // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s1_r)         // output wire [15 : 0] m_axis_data_tdata
);


lowPassStage1 fir_stage1_i (
  .aresetn(a_resetn),                                   // input wire aresetn
  .aclk(a_clk),                                         // input wire aclk
  .s_axis_data_tvalid(s_axis_data_downconverted_s1_v),  // input wire s_axis_data_tvalid
  .s_axis_data_tready(s_axis_data_tready_s1_i),         // output wire s_axis_data_tready
  .s_axis_data_tdata(s_axis_data_downconverted_s1_i),   // input wire [15 : 0] s_axis_data_tdata
  .m_axis_data_tvalid(s_axis_data_filtered_s1_i_v),     // output wire m_axis_data_tvalid
  .m_axis_data_tdata(s_axis_data_filtered_s1_i)         // output wire [15 : 0] m_axis_data_tdata
);  



// ---- STAGE2: 
// İkinci asamada ise sinyal tekrar 1/32 oranında seyreltilir.
// Burada kullanılan IP lowPassStage2 IP'sidir. Birinci asamadan farklı olarak decimation 32 olarak secilir.
// Filtrenin coe dosyası matlab/firFilterS2.m dosyasi ile uretilir.
// Filtre degistirilmek isteniyorsa matlab/firFilter.m scriptindeki Fpass,Fcut degerleri ile oynanarak yeni dosya uretilir.
// Yeni dosyanın etki etmesi için IP tekrar acilmali ve load coe file yapildiktan sonra tekrar generate edilmelidir.
// Burada data rate 1/32 oranında indirildiği için decimation 32 olarak seçilmelidir.  

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
// Son asamada ise sinyal tekrar 1/2 oranında seyreltilir.
// Burada kullanılan IP lowPassStage3 IP'sidir. Birinci asamadan farklı olarak decimation 2 olarak secilir.
// Filtrede 4 farkli secenek vardir.
// s_axis_config_tdata  = 0 -> 3 kHz
// s_axis_config_tdata  = 1 -> 6 kHz
// s_axis_config_tdata  = 2 -> 9 kHz
// s_axis_config_tdata  = 3 -> 12 kHz
// Filtrenin coe dosyası matlab/firFilterS3.m dosyasi ile uretilir.
// Filtre degistirilmek isteniyorsa matlab/firFilter.m scriptindeki Fpass,Fcut degerleri ile oynanarak yeni dosya uretilir.
// Yeni dosyanın etki etmesi için IP tekrar acilmali ve load coe file yapildiktan sonra tekrar generate edilmelidir.
// Burada data rate 1/2 oranında indirildiği için decimation 2 olarak seçilmelidir.  
logic   signed  [D_WIDTH+8-1:0]   s_axis_data_filtered_s3_r  , s_axis_data_filtered_s3_i; 
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
// Nihai sinyal output portlarına burada atanir.
// m_axis_data_tdata_r : I data
// m_axis_data_tdata_i : Q data
// m_axis_data_tvalid  : Valid
// veri hizi 100 MHz/64/64 = 22.4 kHz
always@(posedge a_clk)
begin
    m_axis_data_tdata_r <= $signed(s_axis_data_filtered_s3_r[D_WIDTH-1:0]);
    m_axis_data_tdata_i <= $signed(s_axis_data_filtered_s3_i[D_WIDTH-1:0]);
    m_axis_data_tvalid  <= s_axis_data_filtered_s3_r_v;

end
        
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/06/2022 12:11:53 AM
// Design Name: 
// Module Name: dataProcessor_tb
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


module dataProcessor_tb;

parameter D_WIDTH               = 16;
parameter B_WIDTH               = 16;


integer i=0,s_axis_data_tdata_file,m_axis_data_tdata_r_file,m_axis_data_tdata_i_file,err;
integer stage1_out_r_file,stage1_out_i_file;
integer stage2_out_r_file,stage2_out_i_file;
integer stage3_out_r_file,stage3_out_i_file;

localparam SampleNumber = 2 ** 21;
logic [D_WIDTH-1:0] s_axis_data_tdata_set [SampleNumber-1:0];

    
logic a_clk=0,a_resetn=0;    
    
logic signed [D_WIDTH-1:0]  s_axis_data_tdata=0;
logic signed                s_axis_data_tready;
logic signed                s_axis_data_tvalid=0;

logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r;
logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i;
logic                       m_axis_data_tvalid;

logic        [32-1:0]       ddc_config=30020000;
logic        [2-1:0]        filter_config=0;
logic                       config_valid=0;

dataProcessor #(

    .D_WIDTH               (D_WIDTH),
    .B_WIDTH               (B_WIDTH)
      
    ) uut (
    .s_axis_data_tdata (s_axis_data_tdata),
    .s_axis_data_tready(s_axis_data_tready),
    .s_axis_data_tvalid(s_axis_data_tvalid),
    
    .ddc_config(ddc_config),           
    .filter_config(filter_config),
    .config_valid(config_valid),
    
    .a_clk(a_clk),
    .a_resetn(a_resetn),
    
    .m_axis_data_tdata_r(m_axis_data_tdata_r),
    .m_axis_data_tdata_i(m_axis_data_tdata_i),
    .m_axis_data_tvalid(m_axis_data_tvalid)
        
    );

logic data_enable;
initial
begin
    // MATLAB'da üretilen sinyal (matlab/signalGen.m) burada okunuyor.
    s_axis_data_tdata_file   = $fopen("../../../../matlab/s_axis_data_tdata.txt", "r");

    stage1_out_r_file        = $fopen("../../../../matlab/stage1_out_r.txt", "w");
    stage1_out_i_file        = $fopen("../../../../matlab/stage1_out_i.txt", "w");
    stage2_out_r_file        = $fopen("../../../../matlab/stage2_out_r.txt", "w");
    stage2_out_i_file        = $fopen("../../../../matlab/stage2_out_i.txt", "w");
    stage3_out_r_file        = $fopen("../../../../matlab/stage3_out_r.txt", "w");
    stage3_out_i_file        = $fopen("../../../../matlab/stage3_out_i.txt", "w");
            
    while (! $feof(s_axis_data_tdata_file)) begin //read until an "end of file" is reached.
        err=$fscanf(s_axis_data_tdata_file,"%d\n",s_axis_data_tdata_set[i]); 
        i = i + 1;
    end 
    #20;
    a_resetn = 0;
    #100;
    a_resetn = 1;
    #100;
    data_enable = 0;
    #30;
    config_valid = 1;
    #20;
    config_valid = 0;
    data_enable = 1;
    
    #8000000;
    
    $fclose(s_axis_data_tdata_file);
    $fclose(stage1_out_r_file);
    $fclose(stage1_out_i_file);
    $fclose(stage2_out_r_file);
    $fclose(stage2_out_i_file);
    $fclose(stage3_out_r_file);
    $fclose(stage3_out_i_file);    
    $stop;
end   

logic [21-1:0]  data_count=0;
generate

    always_ff@(posedge a_clk)
    begin
        ddc_config             <= 30019999;
        if(data_enable)
        begin
            data_count          <= data_count + 1;
            s_axis_data_tdata   <= s_axis_data_tdata_set[data_count];
            s_axis_data_tvalid  <= 1;
        end
        else
        begin
            data_count          <= 0;
            s_axis_data_tdata   <= 0;
            s_axis_data_tvalid  <= 0;
        end
    end

endgenerate

// Veriler dosyaya burada yaziliyor. Stage1 Filtre sonucu
always@(posedge a_clk)
if(uut.s_axis_data_filtered_s1_r_v)   begin
    $fwrite(stage1_out_r_file, "%d\n", $signed(uut.s_axis_data_filtered_s1_r[D_WIDTH-1:0]));
    $fwrite(stage1_out_i_file, "%d\n", $signed(uut.s_axis_data_filtered_s1_i[D_WIDTH-1:0]));
end
// Veriler dosyaya burada yaziliyor. Stage2 Filtre sonucu
always@(posedge a_clk)
if(uut.s_axis_data_filtered_s2_r_v)   begin
    $fwrite(stage2_out_r_file, "%d\n", $signed(uut.s_axis_data_filtered_s2_r[D_WIDTH-1:0]));
    $fwrite(stage2_out_i_file, "%d\n", $signed(uut.s_axis_data_filtered_s2_i[D_WIDTH-1:0]));
end
// Veriler dosyaya burada yaziliyor. Stage3 Filtre sonucu
always@(posedge a_clk)
if(uut.s_axis_data_filtered_s3_r_v)   begin
    $fwrite(stage3_out_r_file, "%d\n", $signed(uut.s_axis_data_filtered_s3_r[D_WIDTH-1:0]));
    $fwrite(stage3_out_i_file, "%d\n", $signed(uut.s_axis_data_filtered_s3_i[D_WIDTH-1:0]));
end    
    

always
begin
    a_clk       = 1'b1;
    #2.5 a_clk  = 1'b0;  
    #2.5;
end
    
endmodule


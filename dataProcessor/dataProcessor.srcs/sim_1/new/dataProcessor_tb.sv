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


integer i=0,s_axis_data_tdata_file,m_axis_data_tdata_r_file,m_axis_data_tdata_i_file,stage1_out_r_file,stage1_out_i_file;
localparam SampleNumber = 2 ** 20;
logic [D_WIDTH-1:0] s_axis_data_tdata_set [SampleNumber-1:0];

    
logic a_clk=0,a_resetn=1;    
    
logic signed [D_WIDTH-1:0]  s_axis_data_tdata=0;
logic signed                s_axis_data_tready;
logic signed                s_axis_data_tvalid=0;

logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r;
logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i;
logic                       m_axis_data_tvalid;

logic        [16-1:0]       ddc_config=500;
logic        [16-1:0]       filter_config=0;
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
    s_axis_data_tdata_file   = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/s_axis_data_tdata.txt", "r");
    m_axis_data_tdata_r_file = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/m_axis_data_tdata_r.txt", "w");
    m_axis_data_tdata_i_file = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/m_axis_data_tdata_i.txt", "w");
    stage1_out_r_file        = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/stage1_out_r.txt", "w");
    stage1_out_i_file        = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/stage1_out_i.txt", "w");
    
    while (! $feof(s_axis_data_tdata_file)) begin //read until an "end of file" is reached.
        $fscanf(s_axis_data_tdata_file,"%d\n",s_axis_data_tdata_set[i]); 
        i = i + 1;
    end 
    

    data_enable = 0;
    #30;
    config_valid = 1;
    #20;
    config_valid = 0;
    data_enable = 1;
    
    #800000;
    
    $fclose(s_axis_data_tdata_file);
    $fclose(m_axis_data_tdata_r_file);
    $fclose(m_axis_data_tdata_i_file);
    $stop;
end   

logic [20-1:0]  data_count=0;
generate

    always_ff@(posedge a_clk)
    begin
        ddc_config             <= 500;
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

// Veriler dosyaya burada yazılıyor. Stage1 Filtre sonucu
always@(posedge a_clk)
    if(uut.s_axis_data_filtered_s1_r_v)
    begin
        $fwrite(stage1_out_r_file, "%d\n", uut.s_axis_data_filtered_s1_r);
        $fwrite(stage1_out_i_file, "%d\n", uut.s_axis_data_filtered_s1_i);
    end
    
    
// Veriler dosyaya burada yazılıyor. Outputu MATLAB üzerinden karşılaştırabilirsiniz.
always@(posedge a_clk)
    if(m_axis_data_tvalid)
    begin
        $fwrite(m_axis_data_tdata_r_file, "%d\n", m_axis_data_tdata_r);
        $fwrite(m_axis_data_tdata_i_file, "%d\n", m_axis_data_tdata_i);
    end



always
begin
    a_clk       = 1'b1;
    #2.5 a_clk  = 1'b0;  
    #2.5;
end
    
endmodule


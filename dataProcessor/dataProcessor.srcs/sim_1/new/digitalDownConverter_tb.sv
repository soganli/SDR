`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/05/2022 10:41:19 PM
// Design Name: 
// Module Name: digitalDownConverter_tb
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


module digitalDownConverter_tb;
    parameter D_WIDTH            = 16; // Ratio of data_clk to system_clk
    parameter B_WIDTH             = 16; // 0: SingleRate , 1:Decimation, 2:Interpolation
    

integer i=0,s_axis_data_tdata_file,m_axis_data_tdata_r_file,m_axis_data_tdata_i_file;
localparam SampleNumber = 2 ** 14;
logic [D_WIDTH-1:0] s_axis_data_tdata_set [SampleNumber-1:0];


    
logic a_clk=0,a_resetn=1;    
    
logic signed [D_WIDTH-1:0]  s_axis_data_tdata;
logic signed                s_axis_data_tready;
logic signed                s_axis_data_tvalid;

logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r;
logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i;
logic                       m_axis_data_tvalid;

logic        [16-1:0]       config_data;


digitalDownConverter #(
    .D_WIDTH(D_WIDTH),            
    .B_WIDTH(B_WIDTH)                  
)
uut
(
    .s_axis_data_tdata(s_axis_data_tdata),
    .s_axis_data_tready(s_axis_data_tready),
    .s_axis_data_tvalid(s_axis_data_tvalid),
    
    .config_data(config_data),
    
    .a_clk(a_clk),
    .a_resetn(a_resetn),
    
    .m_axis_data_tdata_r(m_axis_data_tdata_r),
    .m_axis_data_tdata_i(m_axis_data_tdata_i),
    .m_axis_data_tvalid(m_axis_data_tvalid)
    );

logic data_enable;
initial
begin

    s_axis_data_tdata_file   = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/s_axis_data_tdata.txt", "r");
    m_axis_data_tdata_r_file = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/m_axis_data_tdata_r.txt", "w");
    m_axis_data_tdata_i_file = $fopen("/home/soganli/git_workspace/Tbtk/firFilter/matlab/m_axis_data_tdata_i.txt", "w");

    while (! $feof(s_axis_data_tdata_file)) begin //read until an "end of file" is reached.
        $fscanf(s_axis_data_tdata_file,"%d\n",s_axis_data_tdata_set[i]); 
        i = i + 1;
    end 
    

    data_enable = 0;
    #30;
    data_enable = 1;
    
    #64000;
    
    $fclose(s_axis_data_tdata_file);
    $fclose(m_axis_data_tdata_r_file);
    $fclose(m_axis_data_tdata_i_file);
    $stop;
end   

logic [14-1:0]  data_count=0;
generate

    always_ff@(posedge a_clk)
    begin
        config_data             <= 25;
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

always@(posedge a_clk)
    if(m_axis_data_tvalid)
    begin
        $fwrite(m_axis_data_tdata_r_file, "%d\n", m_axis_data_tdata_r);
        $fwrite(m_axis_data_tdata_i_file, "%d\n", m_axis_data_tdata_i);
    end



        
always 
   #2.5 a_clk = ~a_clk;  
    
endmodule


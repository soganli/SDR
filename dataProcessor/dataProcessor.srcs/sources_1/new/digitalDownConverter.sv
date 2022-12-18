`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/04/2022 09:23:14 PM
// Design Name: 
// Module Name: digitalDownConverter
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


module digitalDownConverter #(

    parameter D_WIDTH               = 16,
    parameter B_WIDTH               = 16,
    parameter INPUT_TYPE            = 0
    )(
    input   signed [D_WIDTH-1:0]   s_axis_data_tdata_r,
    input   signed [D_WIDTH-1:0]   s_axis_data_tdata_i,    
    output                         s_axis_data_tready,
    input                          s_axis_data_tvalid,
    
    input   [16-1:0]               config_data,
    
    input                          a_clk,
    input                          a_resetn,
    
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_r=0,
    output  logic signed [D_WIDTH-1:0]  m_axis_data_tdata_i=0,
    output  logic                       m_axis_data_tvalid=0
    );

    generate
    if(INPUT_TYPE == 0) begin    
        localparam COEF_LEN = 10000;
        localparam ROUND_COEF = 2**13;
        
        (* ram_style="block" *)
        logic   [B_WIDTH-1:0]    COEF_MEM_REAL  [COEF_LEN-1:0];
        (* ram_style="block" *)
        logic   [B_WIDTH-1:0]    COEF_MEM_IMAG  [COEF_LEN-1:0];
        
        initial
        begin
            $readmemh("ddcCoefficients1_real.mem", COEF_MEM_REAL);
            $readmemh("ddcCoefficients1_imag.mem", COEF_MEM_IMAG);
        end
        
        reg [16-1:0]    config_data_s=0;
        always_ff@(posedge a_clk)
            config_data_s   <= config_data;
        
        reg [14-1:0]    convertion_cntr=0,coef_index;
        always_ff@(posedge a_clk)
        begin
            if(!a_resetn)
            begin
                convertion_cntr  <= 0;
                coef_index      <= 0;
            end
            else if(s_axis_data_tvalid)
            begin
                convertion_cntr  <= convertion_cntr + config_data_s;
                if(convertion_cntr>=(COEF_LEN-config_data_s))
                begin
                    convertion_cntr <= convertion_cntr - (COEF_LEN-config_data_s);
                    coef_index      <= convertion_cntr; // convertion_cntr - (COEF_LEN-config_data_s);
                end
                else
                begin
                    convertion_cntr <= convertion_cntr + config_data_s;            
                    coef_index      <= convertion_cntr;
                end
            end
        end        
        
        reg signed [D_WIDTH-1:0]   s_axis_data_tdata_s=0,s_axis_data_tdata_ss=0;
        always_ff@(posedge a_clk)
        begin
            s_axis_data_tdata_ss    <= s_axis_data_tdata_s;
            if(s_axis_data_tvalid)
                s_axis_data_tdata_s <= s_axis_data_tdata_r;
        end    

        reg [D_WIDTH+B_WIDTH-1:0]   m_axis_data_tdata_r_pre=0,m_axis_data_tdata_i_pre=0;    
        always_ff@(posedge a_clk)
        begin
            m_axis_data_tdata_r_pre <= s_axis_data_tdata_ss * $signed(COEF_MEM_REAL[coef_index]);
            m_axis_data_tdata_i_pre <= s_axis_data_tdata_ss * $signed(COEF_MEM_IMAG[coef_index]);
        end    

        reg [2:0]   s_axis_data_tvalid_reg=0;
        always_ff@(posedge a_clk)
        begin
            m_axis_data_tdata_r <= (m_axis_data_tdata_r_pre + ROUND_COEF) >>> 14;
            m_axis_data_tdata_i <= (m_axis_data_tdata_i_pre + ROUND_COEF) >>> 14;
            m_axis_data_tvalid  <= s_axis_data_tvalid_reg[2];
        end    
        
        always_ff@(posedge a_clk)
        begin   
            s_axis_data_tvalid_reg  <= {s_axis_data_tvalid_reg[1:0],s_axis_data_tvalid};
        end
                
    end
    else begin
        localparam COEF_LEN = 50000;
        localparam ROUND_COEF = 2**13;
        
        (* ram_style="block" *)
        logic   [B_WIDTH-1:0]    COEF_MEM_REAL  [COEF_LEN-1:0];
        (* ram_style="block" *)
        logic   [B_WIDTH-1:0]    COEF_MEM_IMAG  [COEF_LEN-1:0];
        
        initial
        begin
            $readmemh("ddcCoefficients2_real.mem", COEF_MEM_REAL);
            $readmemh("ddcCoefficients2_imag.mem", COEF_MEM_IMAG);
        end  
        
        reg [16-1:0]    config_data_s=0;
        always_ff@(posedge a_clk)
            config_data_s   <= config_data;
        
        reg [16-1:0]    convertion_cntr=0,coef_index;
        always_ff@(posedge a_clk)
        begin
            if(!a_resetn)
            begin
                convertion_cntr  <= 0;
                coef_index      <= 0;
            end
            else if(s_axis_data_tvalid)
            begin
                convertion_cntr  <= convertion_cntr + config_data_s;
                if(convertion_cntr>=(COEF_LEN-config_data_s))
                begin
                    convertion_cntr <= convertion_cntr - (COEF_LEN-config_data_s);
                    coef_index      <= convertion_cntr; // convertion_cntr - (COEF_LEN-config_data_s);
                end
                else
                begin
                    convertion_cntr <= convertion_cntr + config_data_s;            
                    coef_index      <= convertion_cntr;
                end
            end
        end        
                
        reg signed [D_WIDTH-1:0]   s_axis_data_tdata_r_s=0,s_axis_data_tdata_r_ss=0;
        reg signed [D_WIDTH-1:0]   s_axis_data_tdata_i_s=0,s_axis_data_tdata_i_ss=0;
        always_ff@(posedge a_clk)
        begin
            s_axis_data_tdata_r_ss    <= s_axis_data_tdata_r_s;
            if(s_axis_data_tvalid)
                s_axis_data_tdata_r_s <= s_axis_data_tdata_r;
        end   
        always_ff@(posedge a_clk)
        begin
            s_axis_data_tdata_i_ss    <= s_axis_data_tdata_i_s;
            if(s_axis_data_tvalid)
                s_axis_data_tdata_i_s <= s_axis_data_tdata_i;
        end
        
        reg [D_WIDTH+B_WIDTH-1:0]   m_axis_data_tdata_r1_pre=0,m_axis_data_tdata_i1_pre=0;    
        reg [D_WIDTH+B_WIDTH-1:0]   m_axis_data_tdata_r2_pre=0,m_axis_data_tdata_i2_pre=0;
        reg [D_WIDTH+B_WIDTH-1:0]   m_axis_data_tdata_sum_r=0,m_axis_data_tdata_sum_i=0;            
        always_ff@(posedge a_clk)
        begin
            m_axis_data_tdata_r1_pre <= s_axis_data_tdata_r_ss * $signed(COEF_MEM_REAL[coef_index]);
            m_axis_data_tdata_r2_pre <= s_axis_data_tdata_r_ss * $signed(COEF_MEM_IMAG[coef_index]);
            m_axis_data_tdata_i1_pre <= s_axis_data_tdata_r_ss * $signed(COEF_MEM_REAL[coef_index]);
            m_axis_data_tdata_i2_pre <= s_axis_data_tdata_r_ss * $signed(COEF_MEM_IMAG[coef_index]);   
            
            m_axis_data_tdata_sum_r <=  m_axis_data_tdata_r1_pre - m_axis_data_tdata_i2_pre;
            m_axis_data_tdata_sum_i <=  m_axis_data_tdata_r2_pre + m_axis_data_tdata_i1_pre;            
        end   
        
        reg [3:0]   s_axis_data_tvalid_reg=0;
        always_ff@(posedge a_clk)
        begin
            m_axis_data_tdata_r <= (m_axis_data_tdata_sum_r + ROUND_COEF) >>> 14;
            m_axis_data_tdata_i <= (m_axis_data_tdata_sum_i + ROUND_COEF) >>> 14;
        end    
        
        always_ff@(posedge a_clk)
        begin   
            s_axis_data_tvalid_reg  <= {s_axis_data_tvalid_reg[2:0],s_axis_data_tvalid};
            m_axis_data_tvalid      <= s_axis_data_tvalid_reg[3];            
        end                                 
    end        
    endgenerate    


endmodule

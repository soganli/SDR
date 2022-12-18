
//------------------------------------------------------------------------------
// (c) Copyright 2014 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
//------------------------------------------------------------------------------ 
//
// C Model configuration for the "lowPassStage3" instance.
//
//------------------------------------------------------------------------------
//
// coefficients: -1,-3,-6,-11,-17,-25,-35,-46,-60,-75,-91,-107,-122,-135,-146,-151,-151,-145,-130,-108,-76,-37,11,64,121,180,237,288,331,362,376,372,346,297,225,131,17,-113,-254,-398,-539,-668,-775,-852,-890,-881,-819,-698,-516,-272,31,390,797,1242,1713,2197,2680,3146,3580,3968,4296,4552,4728,4818,4818,4728,4552,4296,3968,3580,3146,2680,2197,1713,1242,797,390,31,-272,-516,-698,-819,-881,-890,-852,-775,-668,-539,-398,-254,-113,17,131,225,297,346,372,376,362,331,288,237,180,121,64,11,-37,-76,-108,-130,-145,-151,-151,-146,-135,-122,-107,-91,-75,-60,-46,-35,-25,-17,-11,-6,-3,-1,0,0,1,1,3,4,6,8,8,7,4,-2,-10,-19,-26,-29,-25,-13,6,30,53,70,73,58,23,-27,-84,-133,-159,-150,-100,-11,100,210,289,310,254,120,-72,-285,-467,-563,-531,-355,-51,326,694,954,1018,828,379,-271,-1000,-1641,-2007,-1931,-1300,-88,1632,3689,5836,7788,9272,10073,10073,9272,7788,5836,3689,1632,-88,-1300,-1931,-2007,-1641,-1000,-271,379,828,1018,954,694,326,-51,-355,-531,-563,-467,-285,-72,120,254,310,289,210,100,-11,-100,-150,-159,-133,-84,-27,23,58,73,70,53,30,6,-13,-25,-29,-26,-19,-10,-2,4,7,8,8,6,4,3,1,1,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,-2,-5,-6,-4,2,10,16,14,2,-17,-33,-34,-14,23,60,73,44,-23,-98,-137,-103,6,144,234,206,44,-189,-370,-373,-151,221,553,633,351,-215,-791,-1033,-710,129,1112,1685,1386,134,-1619,-2985,-2979,-971,2953,7909,12475,15208,15208,12475,7909,2953,-971,-2979,-2985,-1619,134,1386,1685,1112,129,-710,-1033,-791,-215,351,633,553,221,-151,-373,-370,-189,44,206,234,144,6,-103,-137,-98,-23,44,73,60,23,-14,-34,-33,-17,2,14,16,10,2,-4,-6,-5,-2,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,-1,-2,-2,1,5,5,0,-9,-12,-2,16,24,7,-25,-44,-20,38,76,43,-53,-125,-84,67,195,150,-76,-292,-255,74,421,412,-49,-589,-644,-15,808,989,146,-1102,-1520,-397,1533,2428,915,-2310,-4415,-2326,4684,13832,20267,20267,13832,4684,-2326,-4415,-2310,915,2428,1533,-397,-1520,-1102,146,989,808,-15,-644,-589,-49,412,421,74,-255,-292,-76,150,195,67,-84,-125,-53,43,76,38,-20,-44,-25,7,24,16,-2,-12,-9,0,5,5,1,-2,-2,-1,1,1,0,0,0,0,0,0,0,0,0,0,0,0
// chanpats: 173
// name: lowPassStage3
// filter_type: 2
// rate_change: 0
// interp_rate: 1
// decim_rate: 2
// zero_pack_factor: 1
// coeff_padding: 0
// num_coeffs: 128
// coeff_sets: 4
// reloadable: 0
// is_halfband: 0
// quantization: 0
// coeff_width: 16
// coeff_fract_width: 0
// chan_seq: 0
// num_channels: 1
// num_paths: 1
// data_width: 16
// data_fract_width: 0
// output_rounding_mode: 6
// output_width: 16
// output_fract_width: 0
// config_method: 0

const double lowPassStage3_coefficients[512] = {-1,-3,-6,-11,-17,-25,-35,-46,-60,-75,-91,-107,-122,-135,-146,-151,-151,-145,-130,-108,-76,-37,11,64,121,180,237,288,331,362,376,372,346,297,225,131,17,-113,-254,-398,-539,-668,-775,-852,-890,-881,-819,-698,-516,-272,31,390,797,1242,1713,2197,2680,3146,3580,3968,4296,4552,4728,4818,4818,4728,4552,4296,3968,3580,3146,2680,2197,1713,1242,797,390,31,-272,-516,-698,-819,-881,-890,-852,-775,-668,-539,-398,-254,-113,17,131,225,297,346,372,376,362,331,288,237,180,121,64,11,-37,-76,-108,-130,-145,-151,-151,-146,-135,-122,-107,-91,-75,-60,-46,-35,-25,-17,-11,-6,-3,-1,0,0,1,1,3,4,6,8,8,7,4,-2,-10,-19,-26,-29,-25,-13,6,30,53,70,73,58,23,-27,-84,-133,-159,-150,-100,-11,100,210,289,310,254,120,-72,-285,-467,-563,-531,-355,-51,326,694,954,1018,828,379,-271,-1000,-1641,-2007,-1931,-1300,-88,1632,3689,5836,7788,9272,10073,10073,9272,7788,5836,3689,1632,-88,-1300,-1931,-2007,-1641,-1000,-271,379,828,1018,954,694,326,-51,-355,-531,-563,-467,-285,-72,120,254,310,289,210,100,-11,-100,-150,-159,-133,-84,-27,23,58,73,70,53,30,6,-13,-25,-29,-26,-19,-10,-2,4,7,8,8,6,4,3,1,1,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,-2,-5,-6,-4,2,10,16,14,2,-17,-33,-34,-14,23,60,73,44,-23,-98,-137,-103,6,144,234,206,44,-189,-370,-373,-151,221,553,633,351,-215,-791,-1033,-710,129,1112,1685,1386,134,-1619,-2985,-2979,-971,2953,7909,12475,15208,15208,12475,7909,2953,-971,-2979,-2985,-1619,134,1386,1685,1112,129,-710,-1033,-791,-215,351,633,553,221,-151,-373,-370,-189,44,206,234,144,6,-103,-137,-98,-23,44,73,60,23,-14,-34,-33,-17,2,14,16,10,2,-4,-6,-5,-2,1,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,-1,-2,-2,1,5,5,0,-9,-12,-2,16,24,7,-25,-44,-20,38,76,43,-53,-125,-84,67,195,150,-76,-292,-255,74,421,412,-49,-589,-644,-15,808,989,146,-1102,-1520,-397,1533,2428,915,-2310,-4415,-2326,4684,13832,20267,20267,13832,4684,-2326,-4415,-2310,915,2428,1533,-397,-1520,-1102,146,989,808,-15,-644,-589,-49,412,421,74,-255,-292,-76,150,195,67,-84,-125,-53,43,76,38,-20,-44,-25,7,24,16,-2,-12,-9,0,5,5,1,-2,-2,-1,1,1,0,0,0,0,0,0,0,0,0,0,0,0};

const xip_fir_v7_2_pattern lowPassStage3_chanpats[1] = {P_BASIC};

static xip_fir_v7_2_config gen_lowPassStage3_config() {
  xip_fir_v7_2_config config;
  config.name                = "lowPassStage3";
  config.filter_type         = 2;
  config.rate_change         = XIP_FIR_INTEGER_RATE;
  config.interp_rate         = 1;
  config.decim_rate          = 2;
  config.zero_pack_factor    = 1;
  config.coeff               = &lowPassStage3_coefficients[0];
  config.coeff_padding       = 0;
  config.num_coeffs          = 128;
  config.coeff_sets          = 4;
  config.reloadable          = 0;
  config.is_halfband         = 0;
  config.quantization        = XIP_FIR_INTEGER_COEFF;
  config.coeff_width         = 16;
  config.coeff_fract_width   = 0;
  config.chan_seq            = XIP_FIR_BASIC_CHAN_SEQ;
  config.num_channels        = 1;
  config.init_pattern        = lowPassStage3_chanpats[0];
  config.num_paths           = 1;
  config.data_width          = 16;
  config.data_fract_width    = 0;
  config.output_rounding_mode= XIP_FIR_NON_SYMMETRIC_DOWN;
  config.output_width        = 16;
  config.output_fract_width  = 0,
  config.config_method       = XIP_FIR_CONFIG_SINGLE;
  return config;
}

const xip_fir_v7_2_config lowPassStage3_config = gen_lowPassStage3_config();


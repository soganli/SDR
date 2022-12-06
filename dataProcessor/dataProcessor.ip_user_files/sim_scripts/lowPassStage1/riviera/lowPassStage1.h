
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
// C Model configuration for the "lowPassStage1" instance.
//
//------------------------------------------------------------------------------
//
// coefficients: -1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,2,2,3,4,4,5,6,7,9,10,12,13,15,17,19,21,24,27,29,33,36,40,44,48,52,57,62,68,74,80,87,94,101,109,118,127,136,146,157,168,179,192,205,218,233,248,264,280,297,316,335,354,375,397,420,443,468,493,520,548,577,607,638,671,704,739,776,813,852,893,934,978,1022,1069,1116,1166,1217,1269,1324,1380,1437,1497,1558,1621,1685,1752,1821,1891,1963,2038,2114,2192,2273,2355,2440,2526,2615,2706,2798,2894,2991,3090,3192,3296,3402,3510,3621,3734,3849,3967,4086,4208,4333,4459,4588,4719,4853,4989,5127,5267,5409,5554,5701,5850,6002,6156,6311,6469,6629,6792,6956,7122,7291,7461,7633,7808,7984,8162,8342,8523,8707,8892,9078,9267,9457,9648,9841,10035,10231,10428,10626,10825,11026,11227,11430,11633,11837,12042,12248,12455,12662,12869,13077,13286,13494,13703,13912,14121,14330,14539,14748,14956,15164,15372,15579,15786,15991,16196,16401,16604,16806,17007,17207,17406,17603,17798,17993,18185,18376,18565,18752,18937,19119,19300,19479,19655,19829,20000,20168,20334,20497,20658,20815,20970,21121,21270,21415,21556,21695,21830,21961,22089,22214,22334,22451,22565,22674,22779,22881,22978,23071,23160,23245,23326,23403,23475,23543,23607,23666,23720,23771,23817,23858,23895,23927,23954,23977,23996,24010,24019,24024,24024,24019,24010,23996,23977,23954,23927,23895,23858,23817,23771,23720,23666,23607,23543,23475,23403,23326,23245,23160,23071,22978,22881,22779,22674,22565,22451,22334,22214,22089,21961,21830,21695,21556,21415,21270,21121,20970,20815,20658,20497,20334,20168,20000,19829,19655,19479,19300,19119,18937,18752,18565,18376,18185,17993,17798,17603,17406,17207,17007,16806,16604,16401,16196,15991,15786,15579,15372,15164,14956,14748,14539,14330,14121,13912,13703,13494,13286,13077,12869,12662,12455,12248,12042,11837,11633,11430,11227,11026,10825,10626,10428,10231,10035,9841,9648,9457,9267,9078,8892,8707,8523,8342,8162,7984,7808,7633,7461,7291,7122,6956,6792,6629,6469,6311,6156,6002,5850,5701,5554,5409,5267,5127,4989,4853,4719,4588,4459,4333,4208,4086,3967,3849,3734,3621,3510,3402,3296,3192,3090,2991,2894,2798,2706,2615,2526,2440,2355,2273,2192,2114,2038,1963,1891,1821,1752,1685,1621,1558,1497,1437,1380,1324,1269,1217,1166,1116,1069,1022,978,934,893,852,813,776,739,704,671,638,607,577,548,520,493,468,443,420,397,375,354,335,316,297,280,264,248,233,218,205,192,179,168,157,146,136,127,118,109,101,94,87,80,74,68,62,57,52,48,44,40,36,33,29,27,24,21,19,17,15,13,12,10,9,7,6,5,4,4,3,2,2,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1
// chanpats: 173
// name: lowPassStage1
// filter_type: 2
// rate_change: 0
// interp_rate: 1
// decim_rate: 64
// zero_pack_factor: 1
// coeff_padding: 0
// num_coeffs: 512
// coeff_sets: 1
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
// output_width: 18
// output_fract_width: 0
// config_method: 0

const double lowPassStage1_coefficients[512] = {-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,2,2,3,4,4,5,6,7,9,10,12,13,15,17,19,21,24,27,29,33,36,40,44,48,52,57,62,68,74,80,87,94,101,109,118,127,136,146,157,168,179,192,205,218,233,248,264,280,297,316,335,354,375,397,420,443,468,493,520,548,577,607,638,671,704,739,776,813,852,893,934,978,1022,1069,1116,1166,1217,1269,1324,1380,1437,1497,1558,1621,1685,1752,1821,1891,1963,2038,2114,2192,2273,2355,2440,2526,2615,2706,2798,2894,2991,3090,3192,3296,3402,3510,3621,3734,3849,3967,4086,4208,4333,4459,4588,4719,4853,4989,5127,5267,5409,5554,5701,5850,6002,6156,6311,6469,6629,6792,6956,7122,7291,7461,7633,7808,7984,8162,8342,8523,8707,8892,9078,9267,9457,9648,9841,10035,10231,10428,10626,10825,11026,11227,11430,11633,11837,12042,12248,12455,12662,12869,13077,13286,13494,13703,13912,14121,14330,14539,14748,14956,15164,15372,15579,15786,15991,16196,16401,16604,16806,17007,17207,17406,17603,17798,17993,18185,18376,18565,18752,18937,19119,19300,19479,19655,19829,20000,20168,20334,20497,20658,20815,20970,21121,21270,21415,21556,21695,21830,21961,22089,22214,22334,22451,22565,22674,22779,22881,22978,23071,23160,23245,23326,23403,23475,23543,23607,23666,23720,23771,23817,23858,23895,23927,23954,23977,23996,24010,24019,24024,24024,24019,24010,23996,23977,23954,23927,23895,23858,23817,23771,23720,23666,23607,23543,23475,23403,23326,23245,23160,23071,22978,22881,22779,22674,22565,22451,22334,22214,22089,21961,21830,21695,21556,21415,21270,21121,20970,20815,20658,20497,20334,20168,20000,19829,19655,19479,19300,19119,18937,18752,18565,18376,18185,17993,17798,17603,17406,17207,17007,16806,16604,16401,16196,15991,15786,15579,15372,15164,14956,14748,14539,14330,14121,13912,13703,13494,13286,13077,12869,12662,12455,12248,12042,11837,11633,11430,11227,11026,10825,10626,10428,10231,10035,9841,9648,9457,9267,9078,8892,8707,8523,8342,8162,7984,7808,7633,7461,7291,7122,6956,6792,6629,6469,6311,6156,6002,5850,5701,5554,5409,5267,5127,4989,4853,4719,4588,4459,4333,4208,4086,3967,3849,3734,3621,3510,3402,3296,3192,3090,2991,2894,2798,2706,2615,2526,2440,2355,2273,2192,2114,2038,1963,1891,1821,1752,1685,1621,1558,1497,1437,1380,1324,1269,1217,1166,1116,1069,1022,978,934,893,852,813,776,739,704,671,638,607,577,548,520,493,468,443,420,397,375,354,335,316,297,280,264,248,233,218,205,192,179,168,157,146,136,127,118,109,101,94,87,80,74,68,62,57,52,48,44,40,36,33,29,27,24,21,19,17,15,13,12,10,9,7,6,5,4,4,3,2,2,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1};

const xip_fir_v7_2_pattern lowPassStage1_chanpats[1] = {P_BASIC};

static xip_fir_v7_2_config gen_lowPassStage1_config() {
  xip_fir_v7_2_config config;
  config.name                = "lowPassStage1";
  config.filter_type         = 2;
  config.rate_change         = XIP_FIR_INTEGER_RATE;
  config.interp_rate         = 1;
  config.decim_rate          = 64;
  config.zero_pack_factor    = 1;
  config.coeff               = &lowPassStage1_coefficients[0];
  config.coeff_padding       = 0;
  config.num_coeffs          = 512;
  config.coeff_sets          = 1;
  config.reloadable          = 0;
  config.is_halfband         = 0;
  config.quantization        = XIP_FIR_INTEGER_COEFF;
  config.coeff_width         = 16;
  config.coeff_fract_width   = 0;
  config.chan_seq            = XIP_FIR_BASIC_CHAN_SEQ;
  config.num_channels        = 1;
  config.init_pattern        = lowPassStage1_chanpats[0];
  config.num_paths           = 1;
  config.data_width          = 16;
  config.data_fract_width    = 0;
  config.output_rounding_mode= XIP_FIR_NON_SYMMETRIC_DOWN;
  config.output_width        = 18;
  config.output_fract_width  = 0,
  config.config_method       = XIP_FIR_CONFIG_SINGLE;
  return config;
}

const xip_fir_v7_2_config lowPassStage1_config = gen_lowPassStage1_config();


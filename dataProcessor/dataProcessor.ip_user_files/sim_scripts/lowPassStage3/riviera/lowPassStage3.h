
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
// coefficients: 0,0,0,-1,0,1,3,7,12,21,32,46,61,77,91,101,104,96,75,38,-16,-86,-168,-259,-348,-426,-480,-498,-470,-384,-237,-31,228,524,833,1125,1365,1518,1549,1428,1137,671,43,-717,-1558,-2412,-3195,-3815,-4179,-4194,-3786,-2899,-1506,387,2738,5469,8470,11601,14708,17626,20193,22263,23715,24463,24463,23715,22263,20193,17626,14708,11601,8470,5469,2738,387,-1506,-2899,-3786,-4194,-4179,-3815,-3195,-2412,-1558,-717,43,671,1137,1428,1549,1518,1365,1125,833,524,228,-31,-237,-384,-470,-498,-480,-426,-348,-259,-168,-86,-16,38,75,96,104,101,91,77,61,46,32,21,12,7,3,1,0,-1,0,0,0,1,4,9,16,25,34,41,41,31,9,-24,-64,-104,-133,-139,-112,-49,45,156,260,328,333,258,99,-122,-366,-576,-691,-662,-463,-109,346,809,1165,1306,1153,689,-31,-879,-1669,-2195,-2280,-1820,-830,547,2046,3322,4023,3866,2719,660,-2006,-4767,-6982,-7984,-7212,-4331,676,7472,15386,23502,30796,36299,39257,39257,36299,30796,23502,15386,7472,676,-4331,-7212,-7984,-6982,-4767,-2006,660,2719,3866,4023,3322,2046,547,-830,-1820,-2280,-2195,-1669,-879,-31,689,1153,1306,1165,809,346,-109,-463,-662,-691,-576,-366,-122,99,258,333,328,260,156,45,-49,-112,-139,-133,-104,-64,-24,9,31,41,41,34,25,16,9,4,1,0,0,-1,-2,-2,-1,3,8,12,11,3,-12,-29,-36,-26,6,50,83,82,31,-58,-148,-185,-127,25,214,342,315,100,-237,-536,-617,-372,148,722,1039,855,149,-810,-1547,-1597,-774,666,2063,2632,1874,-90,-2446,-3981,-3659,-1228,2473,5711,6579,3960,-1691,-8176,-12178,-10511,-1537,13875,32313,48813,58543,58543,48813,32313,13875,-1537,-10511,-12178,-8176,-1691,3960,6579,5711,2473,-1228,-3659,-3981,-2446,-90,1874,2632,2063,666,-774,-1597,-1547,-810,149,855,1039,722,148,-372,-617,-536,-237,100,315,342,214,25,-127,-185,-148,-58,31,82,83,50,6,-26,-36,-29,-12,3,11,12,8,3,-1,-2,-2,-1,0,0,0,0,0,-1,-1,0,1,3,3,1,-5,-10,-8,3,19,25,8,-27,-53,-40,20,89,100,18,-117,-193,-111,110,306,278,-26,-407,-526,-183,438,833,562,-313,-1140,-1130,-65,1340,1866,798,-1278,-2691,-1967,754,3454,3632,488,-3921,-5844,-2823,3731,8754,7039,-2168,-13057,-15903,-3374,23592,54715,75473,75473,54715,23592,-3374,-15903,-13057,-2168,7039,8754,3731,-2823,-5844,-3921,488,3632,3454,754,-1967,-2691,-1278,798,1866,1340,-65,-1130,-1140,-313,562,833,438,-183,-526,-407,-26,278,306,110,-111,-193,-117,18,100,89,20,-40,-53,-27,8,25,19,3,-8,-10,-5,1,3,3,1,0,-1,-1,0,0,0
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
// coeff_width: 18
// coeff_fract_width: 0
// chan_seq: 0
// num_channels: 1
// num_paths: 1
// data_width: 16
// data_fract_width: 0
// output_rounding_mode: 6
// output_width: 17
// output_fract_width: 0
// config_method: 0

const double lowPassStage3_coefficients[512] = {0,0,0,-1,0,1,3,7,12,21,32,46,61,77,91,101,104,96,75,38,-16,-86,-168,-259,-348,-426,-480,-498,-470,-384,-237,-31,228,524,833,1125,1365,1518,1549,1428,1137,671,43,-717,-1558,-2412,-3195,-3815,-4179,-4194,-3786,-2899,-1506,387,2738,5469,8470,11601,14708,17626,20193,22263,23715,24463,24463,23715,22263,20193,17626,14708,11601,8470,5469,2738,387,-1506,-2899,-3786,-4194,-4179,-3815,-3195,-2412,-1558,-717,43,671,1137,1428,1549,1518,1365,1125,833,524,228,-31,-237,-384,-470,-498,-480,-426,-348,-259,-168,-86,-16,38,75,96,104,101,91,77,61,46,32,21,12,7,3,1,0,-1,0,0,0,1,4,9,16,25,34,41,41,31,9,-24,-64,-104,-133,-139,-112,-49,45,156,260,328,333,258,99,-122,-366,-576,-691,-662,-463,-109,346,809,1165,1306,1153,689,-31,-879,-1669,-2195,-2280,-1820,-830,547,2046,3322,4023,3866,2719,660,-2006,-4767,-6982,-7984,-7212,-4331,676,7472,15386,23502,30796,36299,39257,39257,36299,30796,23502,15386,7472,676,-4331,-7212,-7984,-6982,-4767,-2006,660,2719,3866,4023,3322,2046,547,-830,-1820,-2280,-2195,-1669,-879,-31,689,1153,1306,1165,809,346,-109,-463,-662,-691,-576,-366,-122,99,258,333,328,260,156,45,-49,-112,-139,-133,-104,-64,-24,9,31,41,41,34,25,16,9,4,1,0,0,-1,-2,-2,-1,3,8,12,11,3,-12,-29,-36,-26,6,50,83,82,31,-58,-148,-185,-127,25,214,342,315,100,-237,-536,-617,-372,148,722,1039,855,149,-810,-1547,-1597,-774,666,2063,2632,1874,-90,-2446,-3981,-3659,-1228,2473,5711,6579,3960,-1691,-8176,-12178,-10511,-1537,13875,32313,48813,58543,58543,48813,32313,13875,-1537,-10511,-12178,-8176,-1691,3960,6579,5711,2473,-1228,-3659,-3981,-2446,-90,1874,2632,2063,666,-774,-1597,-1547,-810,149,855,1039,722,148,-372,-617,-536,-237,100,315,342,214,25,-127,-185,-148,-58,31,82,83,50,6,-26,-36,-29,-12,3,11,12,8,3,-1,-2,-2,-1,0,0,0,0,0,-1,-1,0,1,3,3,1,-5,-10,-8,3,19,25,8,-27,-53,-40,20,89,100,18,-117,-193,-111,110,306,278,-26,-407,-526,-183,438,833,562,-313,-1140,-1130,-65,1340,1866,798,-1278,-2691,-1967,754,3454,3632,488,-3921,-5844,-2823,3731,8754,7039,-2168,-13057,-15903,-3374,23592,54715,75473,75473,54715,23592,-3374,-15903,-13057,-2168,7039,8754,3731,-2823,-5844,-3921,488,3632,3454,754,-1967,-2691,-1278,798,1866,1340,-65,-1130,-1140,-313,562,833,438,-183,-526,-407,-26,278,306,110,-111,-193,-117,18,100,89,20,-40,-53,-27,8,25,19,3,-8,-10,-5,1,3,3,1,0,-1,-1,0,0,0};

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
  config.coeff_width         = 18;
  config.coeff_fract_width   = 0;
  config.chan_seq            = XIP_FIR_BASIC_CHAN_SEQ;
  config.num_channels        = 1;
  config.init_pattern        = lowPassStage3_chanpats[0];
  config.num_paths           = 1;
  config.data_width          = 16;
  config.data_fract_width    = 0;
  config.output_rounding_mode= XIP_FIR_NON_SYMMETRIC_DOWN;
  config.output_width        = 17;
  config.output_fract_width  = 0,
  config.config_method       = XIP_FIR_CONFIG_SINGLE;
  return config;
}

const xip_fir_v7_2_config lowPassStage3_config = gen_lowPassStage3_config();


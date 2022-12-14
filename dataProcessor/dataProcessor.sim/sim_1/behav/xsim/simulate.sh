#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2020.2 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Tue Dec 20 03:24:03 +03 2022
# SW Build 3064766 on Wed Nov 18 09:12:47 MST 2020
#
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim dataProcessor_tb_behav -key {Behavioral:sim_1:Functional:dataProcessor_tb} -tclbatch dataProcessor_tb.tcl -view /home/soganli/git_workspace/SDR/dataProcessor/dataProcessor.srcs/sim_1/imports/firFilter/firFilter_tb_behav.wcfg -log simulate.log"
xsim dataProcessor_tb_behav -key {Behavioral:sim_1:Functional:dataProcessor_tb} -tclbatch dataProcessor_tb.tcl -view /home/soganli/git_workspace/SDR/dataProcessor/dataProcessor.srcs/sim_1/imports/firFilter/firFilter_tb_behav.wcfg -log simulate.log


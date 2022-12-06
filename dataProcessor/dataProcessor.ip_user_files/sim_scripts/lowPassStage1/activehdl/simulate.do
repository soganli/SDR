onbreak {quit -force}
onerror {quit -force}

asim +access +r +m+lowPassStage1 -L xbip_utils_v3_0_10 -L axi_utils_v2_0_6 -L fir_compiler_v7_2_15 -L xil_defaultlib -L secureip -O5 xil_defaultlib.lowPassStage1

do {wave.do}

view wave
view structure

do {lowPassStage1.udo}

run -all

endsim

quit -force

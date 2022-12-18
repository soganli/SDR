onbreak {quit -f}
onerror {quit -f}

vsim -voptargs="+acc" -L xbip_utils_v3_0_10 -L axi_utils_v2_0_6 -L fir_compiler_v7_2_15 -L xil_defaultlib -L secureip -lib xil_defaultlib xil_defaultlib.lowPassStage3

do {wave.do}

view wave
view structure
view signals

do {lowPassStage3.udo}

run -all

quit -force

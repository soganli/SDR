onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib lowPassStage2_opt

do {wave.do}

view wave
view structure
view signals

do {lowPassStage2.udo}

run -all

quit -force

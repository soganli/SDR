onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib lowPassStage3_opt

do {wave.do}

view wave
view structure
view signals

do {lowPassStage3.udo}

run -all

quit -force

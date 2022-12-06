onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib lowPassStage1_opt

do {wave.do}

view wave
view structure
view signals

do {lowPassStage1.udo}

run -all

quit -force

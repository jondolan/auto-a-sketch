# ie:
# make run IMG=images/redsox.jpg
# make runprevious
# make simulate
# make motortest

run:
	cd toolpath; \
	node index.js ../$(IMG); \
	cp gcode.gcode ../draw
	cd draw; \
	g++ -std=c++11 -lpthread -lpigpio parser.cc draw.cc -o draw; \
	./draw gcode.gcode

runprevious:
	cd draw; \
	g++ -std=c++11 -lpthread -lpigpio parser.cc draw.cc -o draw; \
	sudo ./draw gcode.gcode

simulate:
	cd draw; \
	g++ -std=c++11 -lpthread parser.cc simulate.cc -o simulate; \
	./simulate gcode.gcode

motortest:
	cd testing; \
	g++ motortest.cc -o motortest; \
	sudo ./motortest
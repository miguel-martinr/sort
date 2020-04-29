bin/mainProg: src/mainProg.cpp bin/DNI.o  include/experimento/Estadistica.hpp include/experimento/exp.hpp
	g++ -g src/mainProg.cpp bin/DNI.o -o bin/mainProg
	
bin/DNI.o:  include/DNI.hpp src/DNI.cpp
	g++ -g -c src/DNI.cpp -o bin/DNI.o

bin/mainTest: src/mainTest.cpp bin/DNI.o
	g++ -g src/mainTest.cpp bin/DNI.o -o bin/mainTest

.PHONY:
clean:
	rm bin/*

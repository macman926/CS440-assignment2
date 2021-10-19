all: minimal morseex test test-kec test-scaling

myTest: myTest.cpp Map.hpp
	g++ -o myTest Map.hpp
minimial: minimal.cpp Map.hpp
	g++ -o minimal minimal.cpp
morseex: morseex.cpp Map.hpp
	g++ -o morseex morseex.cpp
test: test.cpp Map.hpp
	g++ -o test test.cpp
test-kec: test-kec.cpp Map.hpp
	g++ -o test-kec test-kec.cpp
test-scaling: test-scaling.cpp Map.hpp
	g++ -o test-scaling test-scaling.cpp

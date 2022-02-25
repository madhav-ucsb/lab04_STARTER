CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=testbst game


all: ${BINARIES}

tests: ${BINARIES}
	./testbst
	./game
intbst: intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

testbst: testbst.o intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
game: game.o intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
intbst.o: intbst.cpp intbst.h
	${CXX} intbst.cpp -c
testbst.o: testbst.cpp intbst.h 
	${CXX} testbst.cpp -c
game.o: game.cpp intbst.h 
	${CXX} game.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=testbst game


all: ${BINARIES}

tests: ${BINARIES}
	./testbst
	./game
cards: cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

testbst: testbst.o cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
game: main.o cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
cards.o: cards.cpp cards.h
	${CXX} cards.cpp -c
testbst.o: testbst.cpp cards.h 
	${CXX} testbst.cpp -c
main.o: main.cpp cards.h 
	${CXX} main.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
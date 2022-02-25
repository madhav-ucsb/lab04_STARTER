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
game: game.o cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
cards.o: cards.cpp cards.h
	${CXX} cards.cpp -c
testbst.o: testbst.cpp cards.h 
	${CXX} testbst.cpp -c
game.o: game.cpp cards.h 
	${CXX} game.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
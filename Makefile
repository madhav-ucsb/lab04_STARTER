CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=test game


all: ${BINARIES}

tests: ${BINARIES}
	./test
	./game
cards: cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

test: tests.o cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
game: main.o cards.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
cards.o: cards.cpp cards.h
	${CXX} cards.cpp -c
tests.o: tests.cpp cards.h 
	${CXX} tests.cpp -c
main.o: main.cpp cards.h 
	${CXX} main.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
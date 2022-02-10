CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=intbst testbst


all: ${BINARIES}

tests: ${BINARIES}
	./intbst
	./tesbst
intbst: intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

testbst: testbst.o intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

intbst.o: intbst.cpp intbst.h
	${CXX} intbst.cpp -c
testbst.o: testbst.cpp intbst.h 
	${CXX} testbst.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
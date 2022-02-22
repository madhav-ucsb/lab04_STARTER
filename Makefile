CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=intbst testbst


all: ${BINARIES}

tests: ${BINARIES}
	./intbst
	./tesbst
bstheader: bstheader.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
intbst: intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

testbst: testbst.o intbst.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

intbst.o: intbst.cpp intbst.h
	${CXX} intbst.cpp -c
bstheader.o: intbst.h
testbst.o: testbst.cpp
	${CXX} testbst.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o
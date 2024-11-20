CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES = lab07Test01 lab07Test02

all: ${BINARIES}

lab07Test01: lab07Test01.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab07Test02: lab07Test02.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab07Test01
	./lab07Test02

clean:
	/bin/rm -f ${BINARIES} *.o
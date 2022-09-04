CXX = g++
INCLUDE = lib
CXXFLAGS = -g3 -Wall -I$(INCLUDE) -std=c++20
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

utils.o: directorios src/utils.cpp
	$(CXX) $(CXXFLAGS) -c src/utils.cpp -o build/utils.o

compilePolynomial.o: directorios src/compilePolynomial.cpp
	$(CXX) $(CXXFLAGS) -c src/compilePolynomial.cpp -o build/compilePolynomial.o

monomial.o: directorios src/monomial.cpp
	$(CXX) $(CXXFLAGS) -c src/monomial.cpp -o build/monomial.o

polynomial.o: directorios src/polynomial.cpp
	$(CXX) $(CXXFLAGS) -c src/polynomial.cpp -o build/polynomial.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o utils.o compilePolynomial.o monomial.o polynomial.o
	$(CXX) $(CXXFLAGS) -o dist/programa \
	build/main.o build/utils.o build/compilePolynomial.o build/monomial.o build/polynomial.o \
	$(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all

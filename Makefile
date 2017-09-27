CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -O0
CXXINCLUDES=
TARGET=opt_ic

all: src
	$(MAKE) -C src CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" CXXINCLUDES="${CXXINCLUDES}" EXE="${TARGET}"

clean:
	$(MAKE) clean -C src

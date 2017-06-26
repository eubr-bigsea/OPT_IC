CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -O2
CXXINCLUDES=-I/home/biagio/repositories/OPT_Common/include

all: src
	$(MAKE) -C src

clean:
	$(MAKE) clean -C src

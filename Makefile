CXX=g++
CXXFLAGS=-std=c++14 -Wall -g -O0
CXXINCLUDES=-I/home/biagio/repositories/OPT_Common/include
TARGET=opt_ic

all: src
	$(MAKE) -C src CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" CXXINCLUDES="${CXXINCLUDES}" EXE="${TARGET}" && \
	cp src/opt_ic ${TARGET}

clean:
	rm -f ${TARGET}
	$(MAKE) clean -C src

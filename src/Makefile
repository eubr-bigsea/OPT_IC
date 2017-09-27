CXX=g++
CXXFLAGS=-std=c++14 -O3 -DNDEBUG
CXXINCLUDES=
EXE=opt_ic

all: Abstract_optimization.o Create_object.o Fast_bisection_optimization.o Fast_optimization.o opt_ic.o Time_meas.o
	${CXX} ${CXXFLAG} -o ${EXE} Abstract_optimization.o Create_object.o Fast_bisection_optimization.o Fast_optimization.o opt_ic.o Time_meas.o

Abstract_optimization.o: Abstract_optimization.cpp Abstract_optimization.hpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c Abstract_optimization.cpp

Create_object.o: Create_object.cpp Create_object.hpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c Create_object.cpp

Fast_bisection_optimization.o: Fast_bisection_optimization.cpp Fast_bisection_optimization.hpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c Fast_bisection_optimization.cpp

Fast_optimization.o: Fast_optimization.cpp Fast_optimization.hpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c Fast_optimization.cpp

opt_ic.o: opt_ic.cpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c opt_ic.cpp

Time_means.o: Time_meas.cpp Time_meas.hpp
	${CXX} ${CXXFLAGS} ${CXXINCLUDES} -c Time_meas.cpp

clean:
	rm -f *.o
	rm -f ${EXE}

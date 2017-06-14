CXXFLAGS += -Wall -std=c++11 -g
OBJS = main.o Job.o Application.o Stage.o Helper.o Create_application.o \
			Fast_optimization.o Abstract_optimization.o Time_meas.o \
			Fast_bisection_optimization.o Create_object.o InfrastructureConfiguration.o \
			MachineLearningModel.o

EXE = Res_opt


.DEFAULT_GOAL = all

.PHONY: all run clean distclean testclean 

.PRECIOUS: file_names_*.txt config.txt README.txt output_*.txt


all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)

Helper.o: Helper.hpp
Stage.o: Stage.hpp Helper.hpp
Job.o: Job.hpp Stage.hpp Helper.hpp
Application.o: Job.hpp Stage.hpp Application.hpp InfrastructureConfiguration.hpp
Create_application.o: Create_application.hpp Application.hpp Helper.hpp Job.hpp Stage.hpp
Abstract_optimization.o: Abstract_optimization.hpp Job.hpp Stage.hpp Application.hpp Helper.hpp
Fast_optimization.o: Fast_optimization.hpp Job.hpp Stage.hpp Application.hpp Abstract_optimization.hpp Helper.hpp \
			MachineLearningModel.hpp
Fast_bisection_optimization.o: Fast_bisection_optimization.hpp Fast_optimization.hpp Job.hpp Stage.hpp Application.hpp \
	Abstract_optimization.hpp Helper.hpp
Create_object.o: Fast_bisection_optimization.hpp Fast_optimization.hpp Job.hpp Stage.hpp Application.hpp \
	Abstract_optimization.hpp Helper.hpp Time_meas.hpp InfrastructureConfiguration.hpp
main.o: Abstract_optimization.hpp Job.hpp Stage.hpp Helper.hpp Application.hpp Create_application.hpp Fast_optimization.hpp \
	Time_meas.hpp Fast_bisection_optimization.hpp Create_object.hpp Create_object.hpp InfrastructureConfiguration.hpp
Time_meas.o: Time_meas.hpp 
InfrastructureConfiguration.o: InfrastructureConfiguration.hpp
MachineLearningModel.o: MachineLearningModel.hpp
run: all
	./$(EXE) $(ARGS) $(METH)

clean:
	$(RM) *.o result.txt

distclean: clean testclean
	$(RM) $(EXE)
	$(RM) *~

testclean:
	$(RM) output_*.txt



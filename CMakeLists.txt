cmake_minimum_required(VERSION 3.6)
project(VescoviniZaninelli)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Abstract_optimization.cpp
        Abstract_optimization.hpp
        Application.cpp
        Application.hpp
        Create_application.cpp
        Create_application.hpp
        Create_object.cpp
        Create_object.hpp
        Fast_bisection_optimization.cpp
        Fast_bisection_optimization.hpp
        Fast_optimization.cpp
        Fast_optimization.hpp
        Helper.cpp
        Helper.hpp
        Job.cpp
        Job.hpp
        main.cpp
        Stage.cpp
        Stage.hpp
        Time_meas.cpp
        Time_meas.hpp InfrastructureConfiguration.cpp InfrastructureConfiguration.hpp MachineLearningModel.cpp MachineLearningModel.hpp)

add_executable(VescoviniZaninelli ${SOURCE_FILES})
#ifndef _CREATE_OBJ_HPP_
#define _CREATE_OBJ_HPP_

#include <string>
#include "Fast_optimization.hpp"
#include "Fast_bisection_optimization.hpp"
#include "Application.hpp"
#include "Time_meas.hpp"
#include "InfrastructureConfiguration.hpp"

namespace create_object
{
	// this is the function that starts any kind of optimization (simple, fast, fast-bisection)
	unsigned start_optimization(Abstract_optimization& opt);

	// this function creates an object of Fast/Fast_Bisection_optimization and starts the optimization
	void create_obj(std::string method, Application& app);

	// this function sets int the proper way the arguments given to the main with argc and argv
	void set_arguments(std::string& name_of_file, std::string& method, int argc, char** argv);

}

#endif

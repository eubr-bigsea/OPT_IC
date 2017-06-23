#include "Create_object.hpp"

unsigned create_object::start_optimization(Abstract_optimization& opt)
{
	// the optimization function runs and the elapsed time is measured
	time_meas::t_point start = std::chrono::system_clock::now();
	unsigned nu = opt.optimize();
	time_meas::t_point finish = std::chrono::system_clock::now();
	time_meas::t_consumption(start, finish);
	return nu;
}

void create_object::create_obj(std::string method, Application& app)
{
	// variables that will contain the results of the optimization
	unsigned nuf = 0;
	unsigned nub = 0;

	// we check which methods were indicated in the string "method",
	// we run them and then print che result and the number of iterations.
	// If we are making the deadline test there is a loop in the fast and fast-bisection
	// optimization with a decreasing deadline

	if(method.find_first_of("fF") + 1)
	{
		Fast_optimization opt(app);
		nuf = start_optimization(opt);
		std::cout << "\nOptimum Ncores using fast optimization: "<< nuf << std::endl;
		std::cout << "Iterations using fast optimization: " << opt.get_it() << '\n' << std::endl;
		app.get_infr_config().print();
		std::cout << "N YARN containers (VMs): " << app.get_infr_config().get_n_containers(nuf) << '\n' << std::endl;



	}

	if(method.find_first_of("bB") + 1)
	{
		Fast_bisection_optimization opt(app);
		nub = start_optimization(opt);
		std::cout << "\nOptimum Ncores with using fast optimization with bisection: "<< nub << std::endl;
		std::cout << "Iterations using fast optimization with bisection: " << opt.get_it() << '\n' << std::endl;


	}



}

void create_object::set_arguments(std::string& name_of_file, std::string& method, int argc, char** argv)
{
	// if the name of the file to been opened hasn't been provided one can insert it
	if(argc == 1 )
  {
    std::cout << "Missing arguments, usage input_file opt_method" << std::endl;
    exit(-1);
  }
  else
    name_of_file = argv[1];

	// if the method to be used hasn't been provided one can insert it; in the case of
	// multiple method the corresponding letters can be typed both with and without spaces
  if(argc == 2)
  {
      std::cout << "Missing arguments, usage input_file opt_method" << std::endl;
      exit(-1);
  }
  else
    method = argv[2];

  if(argc == 4)
    method += argv[3];

  if(argc == 5)
    method = method + argv[3] + argv[4];
}

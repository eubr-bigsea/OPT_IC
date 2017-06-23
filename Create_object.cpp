/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli
Copyright 2017 Biagio Festa <biagio.festa@gmail.com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <string>
#include "Create_object.hpp"

unsigned create_object::start_optimization(Abstract_optimization& opt, bool no_ml)
{
	// the optimization function runs and the elapsed time is measured
	time_meas::t_point start = std::chrono::system_clock::now();
	unsigned nu = opt.optimize(no_ml);
	time_meas::t_point finish = std::chrono::system_clock::now();
	time_meas::t_consumption(start, finish);
	return nu;
}

void create_object::create_obj(const OptimizeMethod& optimize_method,
                               Application& app, bool no_ml) {
  // variables that will contain the results of the optimization
  unsigned nuf = 0;
  unsigned nub = 0;

  // we check which methods were indicated in the string "method",
  // we run them and then print che result and the number of iterations.
  // If we are making the deadline test there is a loop in the fast and
  // fast-bisection optimization with a decreasing deadline

  if (optimize_method == OptimizeMethod::FAST_OPTIMIZATION) {
    Fast_optimization opt(app);
    nuf = start_optimization(opt, no_ml);
    std::cout << "\nOptimum Ncores using fast optimization: " << nuf
              << std::endl;
    std::cout << "Iterations using fast optimization: " << opt.get_it() << '\n'
              << std::endl;
    app.get_infr_config().print();
    std::cout << "N YARN containers (VMs): "
              << app.get_infr_config().get_n_containers(nuf) << '\n'
              << std::endl;
  } else if (optimize_method == OptimizeMethod::FAST_BISECT_OPTIMIZATION) {
    Fast_bisection_optimization opt(app);
    nub = start_optimization(opt, no_ml);
    std::cout
        << "\nOptimum Ncores with using fast optimization with bisection: "
        << nub << std::endl;
    std::cout << "Iterations using fast optimization with bisection: "
              << opt.get_it() << '\n'
              << std::endl;
  }
}

create_object::CommandLineOptions create_object::parse_command_line(
    int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Missing arguments.\n"
              << "Usage:\n"
              << argv[0] << " input_file -(f|F|b|B) [--no-ml]\n";
    exit(-1);
  }

  CommandLineOptions options;
  options.no_ml = false;

  // Get the name of the input file
  options.name_of_file = argv[1];

  // Parse the optimization method
  if (argc >= 2) {
    std::string method_arg = argv[2];

    // Clean dash before
    auto finder = method_arg.find_first_not_of('-');
    method_arg = method_arg.substr(finder);

    // Check should be one single char
    if (method_arg.size() != 1) {
      std::cerr << "The optimize method should be expressed with a single "
                   "character.\n";
      exit(-1);
    }

    const char method_char = method_arg.at(0);
    switch (method_char) {
      case 'f':
      case 'F':
        options.optimize_method = OptimizeMethod::FAST_OPTIMIZATION;
        break;
      case 'b':
      case 'B':
        options.optimize_method = OptimizeMethod::FAST_BISECT_OPTIMIZATION;
        break;
      default:
        std::cerr << "Optimize method ('" << method_char
                  << "') not recognized\n";
        exit(-1);
    }
  }

  // Check for --no-ml option
  if (argc >= 4) {
    std::string method_arg = argv[3];

    if (method_arg == "--no-ml") {
      options.no_ml = true;
    } else {
      std::cerr << "Option '" << method_arg << "' not recognized\n";
    }
  }

  return options;
}

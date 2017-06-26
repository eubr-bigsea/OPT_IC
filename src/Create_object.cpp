/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli
Copyright 2017 Biagio Festa <info@biagiofesta.it>

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

#include "Create_object.hpp"
#include <string>

unsigned create_object::start_optimization(Abstract_optimization& opt,
                                           bool no_ml) {
  // the optimization function runs and the elapsed time is measured
  time_meas::t_point start = std::chrono::system_clock::now();
  unsigned nu = opt.optimize(no_ml);
  time_meas::t_point finish = std::chrono::system_clock::now();
  time_meas::t_consumption(start, finish);
  return nu;
}

void create_object::create_obj(
    const opt_common::CommandLineParser::OptimizeMethod& optimize_method,
    opt_common::Application& app, bool no_ml) {
  // variables that will contain the results of the optimization
  unsigned nuf = 0;
  unsigned nub = 0;

  // we check which methods were indicated in the string "method",
  // we run them and then print che result and the number of iterations.
  // If we are making the deadline test there is a loop in the fast and
  // fast-bisection optimization with a decreasing deadline

  if (optimize_method ==
      opt_common::CommandLineParser::OptimizeMethod::FAST_OPTIMIZATION) {
    Fast_optimization opt(app);
    nuf = start_optimization(opt, no_ml);
    std::cout << "\nOptimum Ncores using fast optimization: " << nuf
              << std::endl;
    std::cout << "Iterations using fast optimization: " << opt.get_it() << '\n'
              << std::endl;
    app.get_infrastructure_config().print();
    std::cout << "N YARN containers (VMs): "
              << app.get_infrastructure_config().get_n_containers(nuf) << '\n'
              << std::endl;
  } else if (optimize_method == opt_common::CommandLineParser::OptimizeMethod::
                                    FAST_BISECT_OPTIMIZATION) {
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

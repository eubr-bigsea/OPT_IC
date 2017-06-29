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

#ifndef _ABS_OPTIMIZATION_HPP_
#define _ABS_OPTIMIZATION_HPP_

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <opt_common/Application.hpp>
#include <opt_common/helper.hpp>
#include <opt_common/MachineLearningModel.hpp>
#include <string>

class Abstract_optimization {
 protected:
  opt_common::TimeInstant deadline;

  // maximum number of task in a single stage of the application,
  // it is the maximum  parallelization level that can be achieved
  const unsigned max_n_cores;

  // Initial values of alpha and beta of the hyperbole y = alpha/x + beta
  double alphain;
  double betain;

  // number of iterations
  unsigned it = 0;

  // string with the name of the lua file without the extension

  const std::string lua_name;
  // string with the command to run Dagsim
  const std::string dagsim_command;

  // function that evaluates the execution time with nu cores using Dagsim
  opt_common::TimeInstant evaluate_time(unsigned nu) const;

  // computes the number of cores to fulfil the deadline given the hyperbole y =
  // alpha/x + beta
  unsigned get_nu(const double alpha, const double beta);

  opt_common::MachineLearningModel mlm;
  opt_common::InfrastructureConfiguration ic;

 public:
  Abstract_optimization(opt_common::Application& app)
      : deadline(app.get_deadline()),
        max_n_cores(app.compute_max_number_of_task()),
        lua_name(app.get_lua_name()),
        dagsim_command(opt_common::get_dagsim_command(app.get_lua_name(),
                                                      app.get_dagsim_path())),
        mlm(app.get_machine_learning_model()),
        ic(app.get_infrastructure_config()) {
    // we compute alpha and beta of the hyperbole using 1 and the max_n_cores
    app.set_alpha_beta(1, max_n_cores);
    alphain = app.get_alpha();
    betain = app.get_beta();
  }

  // function that computes the optimum number of cores
  virtual unsigned optimize(const bool no_ml) = 0;

  double get_deadline() const { return deadline; }
  virtual double get_alpha() const { return alphain; }
  virtual double get_beta() const { return betain; }

  // return the number if iterations
  unsigned get_it() const { return it; }

  virtual ~Abstract_optimization() = default;
};

#endif

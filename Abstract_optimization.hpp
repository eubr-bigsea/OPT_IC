#ifndef _ABS_OPTIMIZATION_HPP_
#define _ABS_OPTIMIZATION_HPP_

#include "Application.hpp"
#include "Helper.hpp"
#include "MachineLearningModel.hpp"
#include "InfrastructureConfiguration.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

class Abstract_optimization
{
protected:

   help::time_instant deadline;

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
  help::time_instant evaluate_time(unsigned nu) const;

  // computes the number of cores to fulfil the deadline given the hyperbole y = alpha/x + beta
  unsigned get_nu(const double alpha, const double beta);

    MachineLearningModel mlm;
    InfrastructureConfiguration ic;

public:
  Abstract_optimization(Application& app):
          deadline(app.get_deadline()), max_n_cores(app.get_max_tasks()),
          lua_name(app.get_lua_name()), dagsim_command(help::get_dagsim_command(lua_name)),
          mlm(app.get_mlm()), ic(app.get_infr_config())
  {
    // we compute alpha and beta of the hyperbole using 1 and the max_n_cores
    app.set_alpha_beta(1, max_n_cores);
    alphain = app.get_alpha();
    betain = app.get_beta();
  }

  // function that computes the optimum number of cores
  virtual unsigned optimize() = 0;

  double get_deadline() const { return deadline;}
  virtual double get_alpha() const { return alphain;}
  virtual double get_beta() const { return betain;}

  // return the number if iterations
  unsigned get_it() const { return it;}

  virtual ~Abstract_optimization() = default;

};

#endif

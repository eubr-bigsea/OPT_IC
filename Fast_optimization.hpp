#ifndef _FAST_OPTIMIZATION_HPP_
#define _FAST_OPTIMIZATION_HPP_

#include "Abstract_optimization.hpp"
#include "InfrastructureConfiguration.hpp"
#include "MachineLearningModel.hpp"
#include "Helper.hpp"
#include <utility>

class Fast_optimization : public Abstract_optimization
{
protected:

  // alpha and beta of the hyperbole that are changed at every iteration
  double alpha;
  double beta;

  // current maximum number of virtual machines above the deadline (numin)
  // and current minimum number of virtual machines below the deadline (numax)
  // the final optimum result must be in the range [numin, numax] and it is found
  // when numax - numin == 1
  unsigned numin = 1;
  unsigned numax;



  // tmin is the evaluation of numin, tmax is the evaluation of numax
  help::time_instant tmin;
  help::time_instant tmax;

  // function that computes the hyperbole y = alpha/x + beta given two points (n1, r1) and (n2, r2)
  void set_alpha_beta(const unsigned n1,const unsigned n2, const help::time_instant r1, const help::time_instant r2);

  // verify if the last iteration is is oscillating
  bool is_oscillating(const unsigned nu) const;

  // this function changes numin and numax: if t > deadline then numin = nu otherwise numax = nu
  void assigne_nu_time(const unsigned nu, const help::time_instant t);

public:
  Fast_optimization(Application& app)
    : Abstract_optimization(app), alpha(alphain), beta(betain), numax(max_n_cores) {}

  // function that computes the optimum numer of VM
  unsigned optimize() override;

  double get_alpha() const override { return alpha;}
  double get_beta() const override { return beta;}

  virtual ~Fast_optimization() = default;


};

#endif

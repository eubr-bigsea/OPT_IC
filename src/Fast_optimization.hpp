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

#ifndef _FAST_OPTIMIZATION_HPP_
#define _FAST_OPTIMIZATION_HPP_

#include <utility>
#include "Abstract_optimization.hpp"

class Fast_optimization : public Abstract_optimization {
 protected:
  // alpha and beta of the hyperbole that are changed at every iteration
  double alpha;
  double beta;

  // current maximum number of virtual machines above the deadline (numin)
  // and current minimum number of virtual machines below the deadline (numax)
  // the final optimum result must be in the range [numin, numax] and it is
  // found
  // when numax - numin == 1
  unsigned numin = 1;
  unsigned numax;

  // tmin is the evaluation of numin, tmax is the evaluation of numax
  opt_common::TimeInstant tmin;
  opt_common::TimeInstant tmax;

  // function that computes the hyperbole y = alpha/x + beta given two points
  // (n1, r1) and (n2, r2)
  void set_alpha_beta(const unsigned n1, const unsigned n2,
                      const opt_common::TimeInstant& r1,
                      const opt_common::TimeInstant& r2);

  // verify if the last iteration is is oscillating
  bool is_oscillating(const unsigned nu) const;

  // this function changes numin and numax: if t > deadline then numin = nu
  // otherwise numax = nu
  void assigne_nu_time(const unsigned nu, const opt_common::TimeInstant& t);

 public:
  Fast_optimization(opt_common::Application& app)
      : Abstract_optimization(app),
        alpha(alphain),
        beta(betain),
        numax(max_n_cores) {}

  // function that computes the optimum numer of VM
  unsigned optimize(const bool no_ml) override;

  double get_alpha() const override { return alpha; }
  double get_beta() const override { return beta; }

  virtual ~Fast_optimization() = default;
};

#endif

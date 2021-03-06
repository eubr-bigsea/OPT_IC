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

#ifndef _FASTBIS_OPTIMIZATION_HPP_
#define _FASTBIS_OPTIMIZATION_HPP_

#include "Fast_optimization.hpp"

class Fast_bisection_optimization : public Fast_optimization {
 private:
  // use bisection when the solution oscillates
  void bisection();

 public:
  Fast_bisection_optimization(opt_common::Application& app)
      : Fast_optimization(app) {}

  // function that computes the optimum numer of VM
  unsigned optimize(const bool no_ml) override;
};

#endif

/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli

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

#include "Fast_bisection_optimization.hpp"

unsigned Fast_bisection_optimization::optimize(const bool no_ml)
{
  std::cout << "---------------------------------------------------------------" << std::endl;
  std::cout << "\nStarting fast optimization with bisection - deadline: " << deadline << " ms\n" << std::endl;

  // if the evaluated time is less then the deadline with just one virtual machine
  // the result is 1
  tmin = evaluate_time(numin);
  if(tmin < deadline)
  {
  	std::cout << "Ncores = " << numin << " -> time = " << tmin << " ms"<< std::endl;
  	return numin;
  }

  // if the evaluated time with max_n_cores if greater then the deadline we can't do
  // any better, the deadline is too restrictive
  tmax = evaluate_time(numax);
  if(tmax > deadline)
  {
  	std::cout << "Ncores = " << numax << " -> time = " << tmax << " ms"<< std::endl;
    std::cerr << "The deadline is too restrictive" << std::endl;
    return 0;
  }

  unsigned nu = (no_ml == true ? get_nu(alphain, betain)
                 : mlm.initial_core_numbers(ic, deadline));

  // while nu isn't oscillating its time is evaluated and assigned to numax or numin,
  // if the difference between numax and numin is now one numax is returned,
  // otherwise we proceed computing a new hyperbole
  while(!is_oscillating(nu))
  {
      help::time_instant t = evaluate_time(nu);
  	assigne_nu_time(nu , t);

  	std::cout << "Ncores = " << nu << " -> time = " << t << " ms" <<std::endl;

  	if(numax - numin == 1)
    	return numax;

  	set_alpha_beta(numin, numax, tmin, tmax);

  	nu = get_nu(alpha, beta);
	}

  // if we exit from the while loop we go on with the bisection until the final result is found
	bisection();

  return numax;
}

void Fast_bisection_optimization::bisection()
{
	unsigned nu;
    help::time_instant t;

	std::cout << "Starting bisection" <<std::endl;

  // we don't take into account as an iteration the one that has caused the oscillation
  it--;

  while(numax - numin != 1)
  {
    nu = std::ceil(double(numax + numin) / 2.);
    t = evaluate_time(nu);
    it++;

    std::cout << "Ncores = " << nu << " -> time = " << t << " ms" <<std::endl;

    assigne_nu_time(nu,t);
  }
}

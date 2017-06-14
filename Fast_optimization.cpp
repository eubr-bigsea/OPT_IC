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

#include "Fast_optimization.hpp"

void Fast_optimization::set_alpha_beta(const unsigned n1, const unsigned n2, const help::time_instant r1, const help::time_instant r2)
{
  if (n1 == n2)
  {
    std::cerr << "n1 = n2" << '\n';
    return;
  }

  // n1 and n2 are unsigned so we have to differentiates the two cases in order
  // to have a positive difference
  if(n1 > n2)
  {
    alpha = double(r2 - r1) * n1 * n2 / (n1 - n2);
    beta = double(r1) - alpha / n1;
  }
  else
  {
    alpha = double(r1 - r2) * n1 * n2 / (n2 - n1);
    beta = double(r1) - alpha / n1;
  }
}

unsigned Fast_optimization::optimize()
{
  std::cout << "---------------------------------------------------------------" << std::endl;
  std::cout << "\nStarting fast optimization - deadline: " << deadline << " ms\n" << std::endl;


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


  // we evaluate the nu computed with the initial alpha and beta and then we assign
  // it nu numin or numax
  unsigned nu_old = get_nu(alphain, betain);


    unsigned nu = mlm.initial_core_numbers(ic,deadline);
  help::time_instant t = evaluate_time(nu);
    std::cout << "Ncores (alpha & beta) = " << nu_old << " -> time = " << t << " ms"<< std::endl;
  std::cout << "Ncores = " << nu << " -> time = " << t << " ms"<< std::endl;
  assigne_nu_time(nu,t);

  // until we find a numax and a numin such that numax - numin == 1
  // we use them to computed a new hyperbole from which we compute a new nu,
  // in the case that there is an oscillation we discard it and recompute it
  // as the average of numin and numax
  while(numax - numin != 1)
  {
  	set_alpha_beta(numin, numax, tmin, tmax);
  	nu = get_nu(alpha, beta);

    if(is_oscillating(nu))
      nu = std::ceil(double(numin + numax) / 2.);

  	t = evaluate_time(nu);

    std::cout << "Ncores = " << nu << " -> time = " << t << " ms" <<std::endl;
    assigne_nu_time(nu , t);
	}

  return numax;
}

// there is an oscillation when the new nu is less then or equal to numin
// or greater or equal to numax
bool Fast_optimization::is_oscillating(const unsigned nu) const
{
  return (nu <= numin || nu >= numax);

}

// if t is greater then the deadline the new nu becomes numin and t becomes timin;
// otherwise nu becomes numax and t becomes tmax
void Fast_optimization::assigne_nu_time(const unsigned nu, const help::time_instant t)
{
	if(t > deadline)
  {
		numin = nu;
		tmin = t;
	}
	else
  {
		numax = nu;
		tmax = t;
	}
}



#ifndef _FASTBIS_OPTIMIZATION_HPP_
#define _FASTBIS_OPTIMIZATION_HPP_

#include "Fast_optimization.hpp"


class Fast_bisection_optimization : public Fast_optimization
{
private:

	//use bisection when the solution oscillates
	void bisection();

public:
  Fast_bisection_optimization(Application& app): Fast_optimization(app) {}

  // function that computes the optimum numer of VM
  unsigned optimize() override;

};

#endif

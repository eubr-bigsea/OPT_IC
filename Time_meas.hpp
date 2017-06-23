#ifndef _TIME_MEAS_HPP_
#define _TIME_MEAS_HPP_

#include <chrono>
#include <ctime>
#include <iostream>

namespace time_meas
{
  typedef std::chrono::milliseconds milli;
  typedef std::chrono::time_point<std::chrono::system_clock> t_point;

  // functions that prints the  finish - start time
  void t_consumption(t_point start, t_point finish);
}

#endif

#include "Time_meas.hpp"

void time_meas::t_consumption(t_point start, t_point finish)
{
  std::chrono::duration<double> elapsed_seconds = finish - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t (finish);
  std::cout << "\nFinished computation at " << std::ctime (&end_time)
            << "Elapsed time: " << elapsed_seconds.count() << " s"
            << std::endl;
}

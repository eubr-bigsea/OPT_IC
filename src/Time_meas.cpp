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

#include "Time_meas.hpp"

void time_meas::t_consumption(t_point start, t_point finish) {
  std::chrono::duration<double> elapsed_seconds = finish - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(finish);
  std::cout << "\nFinished computation at " << std::ctime(&end_time)
            << "Elapsed time: " << elapsed_seconds.count() << " s" << std::endl;
}

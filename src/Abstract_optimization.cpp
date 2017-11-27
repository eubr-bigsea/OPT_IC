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
#include <string>
#include "Abstract_optimization.hpp"

unsigned Abstract_optimization::get_nu(const double alpha, const double beta) {
  it++;
  return std::ceil(alpha / (deadline - beta));
}

opt_common::TimeInstant Abstract_optimization::evaluate_time(
    unsigned nu) const {
  // we open the .lua file and we set nu in the line where it's written
  // the number of cores (nodes) to be used in the simulation
  std::ifstream is(lua_name);
  if (!is) {
    std::cerr << "Error openinig file " << lua_name << std::endl;
    return -1;
  }
  std::ofstream os{lua_name + "_mod.lua"};
  const std::string tofind = "Nodes = @@nodes@@;";
  std::string n_nodes = "Nodes = ";
  n_nodes += std::to_string(nu) + ";";
  std::string line;

  while (getline(is, line)) {
    if (line == tofind)
      os << n_nodes << std::endl;
    else
      os << line << std::endl;
  }
  os.close();
  // we call Dagsim and send its output in the file result.txt, then we read and
  // return it
  system(dagsim_command.c_str());
  std::ifstream is2{"result.txt"};
  opt_common::TimeInstant res;
  if (!is2) {
    std::cerr << "Error opening the result file" << std::endl;
    return -1;
  }

  is2 >> res;
  if (res <= 0.0) {
    std::cerr << "Error in dagsim result: result.txt" << std::endl;
    std::cerr << "Dagsim command was: " << dagsim_command << std::endl;
    exit(1);
  }
  return res;
}

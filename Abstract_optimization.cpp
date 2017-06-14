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

#include "Abstract_optimization.hpp"

unsigned Abstract_optimization::get_nu(const double alpha, const double beta)
{
  it++;
  return std::ceil(alpha / (deadline - beta));
}

help::time_instant Abstract_optimization::evaluate_time(unsigned nu) const
{
  // we open the .lua file and we set nu in the line where it's written
  // the number of cores (nodes) to be used in the simulation
  std::ifstream is{lua_name + ".lua"};
  if(!is)
  {
    std::cerr << "Error openinig file .lua" << std::endl;
    return -1;
  }
  std::ofstream os{lua_name + "_mod.lua"};
  const std::string tofind = "Nodes = @@nodes@@;";
  std::string n_nodes = "Nodes = ";
  n_nodes += std::to_string(nu) + ";";
  std::string line;

  while(getline(is, line))
  {
    if(line == tofind)
      os << n_nodes << std::endl;
    else
      os << line << std::endl;
  }

  // we call Dagsim and send its output in the file result.txt, then we read and return it
  system(dagsim_command.c_str());
  std::ifstream is2{"result.txt"};
  help::time_instant res;
  if(!is2)
  {
    std::cerr << "Error opening the result file" << std::endl;
    return -1;
  }

  is2 >> res;
  return res;
}


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

#include "Stage.hpp"

void Stage::set_dependencies(const std::vector<help::id_type>& v)
{
  dependencies = v;
}

void Stage::set_max(const std::vector<help::time_instant>& v)
{
  //max execution time in a stage
  help::time_instant temp = 0;
  for(auto t : v)
    if(t > temp)
      temp = t;

  max = temp;
}

void Stage::set_min(const std::vector<help::time_instant>& v)
{
  //min execution time in a stage
  help::time_instant temp = v[0];
  for(auto t : v)
    if(t < temp)
      temp = t;

  min = temp;
}

void Stage::set_avg(const std::vector<help::time_instant>& v)
{
  //avg execution time in a stage
  help::time_instant sum = 0.;
  for(auto t : v)
    sum += t;

  avg = sum / v.size();
}

void Stage::prints() const
{
  std::cout  << '\n';
  std::cout << "Id stage: " << id_Stage << '\n' << " avg time: " << this->get_avg() << '\n';
  std::cout << "Number of tasks: " << n_tasks << '\n';
  if(dependencies.empty())
  {
    std::cout << "No dependencies on other stages" << '\n';
  }
  else
  {
    std::cout << "dependencies on stages: " << '\n';
    for (size_t i = 0; i < dependencies.size(); i++)
      std::cout << dependencies[i] << " ";
      
    std::cout << '\n';
  }
}

Stage& Stage::operator=(const Stage& stage)
{
  id_Stage = stage.get_ID();
  max = stage.get_max();
  min = stage.get_min();
  n_tasks = stage.get_n_tasks();
  dependencies = stage.get_depend();
  avg = stage.get_avg();
  return *this;
}

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

#include "Job.hpp"

help::time_instant Job::get_completion_time() const
{
  return completion_time;
}

help::time_instant Job::get_submission_time() const
{
  return submission_time;
}

help::id_type Job::get_ID() const
{
  return id;
}

void Job::set_completion_time (help::time_instant t)
{
  completion_time = t;
}

void Job::set_submission_time (help::time_instant t)
{
  submission_time = t;
}

void Job::set_id_stages(const std::vector<help::id_type>& v)
{
  id_stages = v;
}

void Job::print() const
{
  std::cout << "id job: " << id << '\n' << " submission_time " << submission_time << '\n'
            << " completion_time " << completion_time << '\n';
}

Job& Job::operator=(const Job& j)
{
  id = j.get_ID();
  id_app = j.get_id_app();
  submission_time = j.get_submission_time();
  completion_time = j.get_completion_time();
  id_stages = j.get_id_stages();
  return *this;
}

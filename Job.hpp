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

#ifndef _JOB_HPP_
#define _JOB_HPP_

#include <iostream>
#include <vector>
#include "Stage.hpp"
#include "Helper.hpp"


class Job
{
public:

  Job (help::id_type j_id, std::string id_a, help::time_instant sub_time, help::time_instant compl_time)
    : id (j_id), id_app(id_a), submission_time (sub_time), completion_time (compl_time) {}

    help::time_instant get_submission_time() const;
    help::time_instant get_completion_time() const;
    help::id_type get_ID() const;
  const std::vector<help::id_type>& get_id_stages() const {return id_stages;}
  const std::string& get_id_app() const {return id_app;}

  void set_submission_time(help::time_instant submission_time);
  void set_completion_time(help::time_instant completion_time);
  void set_id(help::id_type id_temp);
  void set_id_stages(const std::vector<help::id_type>& v);
  void print() const;

  Job& operator=(const Job&);

private:
    help::id_type id;
  std::string id_app;
    help::time_instant submission_time;
    help::time_instant completion_time;
  std::vector<help::id_type> id_stages;
};

#endif

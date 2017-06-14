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

#ifndef _HELPER_HPP_
#define _HELPER_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <list>

namespace help
{
  typedef unsigned int id_type;
  typedef long int time_instant;


  //read from s dependencies dropping square brackets
  unsigned long read_id(std::string& s);

  // create a vector of vectors of string from an input file
  void create_vector(const std::string& file_name, std::vector<std::vector<std::string> >& v);



  //check if string s, including dependencies, is empty
  bool check_empty(const std::string& s);

  // adds to the string name the full path of the data directory
  // read from the file config.txt
  void add_data_dir(std::string& name);


    // adds to the string name the full path of the lua directory
    // read from the file config.txt
  void add_lua_dir(std::string& name);

  // prepares the command to call dagsim
  std::string get_dagsim_command(const std::string& name);

}
#endif

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


  // get the application configuration file name
  // read from the file config.txt
  void add_config_file(std::string& name);

  // prepares the command to call dagsim
  std::string get_dagsim_command(const std::string& name);

}
#endif

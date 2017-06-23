#include "Helper.hpp"

//check if string s, including dependencies, is empty
bool help::check_empty(const std::string& s)
{

  if(s[0] == '[' && s[1] == ']')
    return true;
  return false;
}

//read from s dependencies dropping square brackets
unsigned long help::read_id(std::string& s)
{

  std::string copy;
  for (unsigned i = 0; i < s.size(); i++)
  {
    if(isdigit(s[i])){
      copy += s[i];
    }
  }
  return std::atol(copy.c_str());
}


// create a vector of vectors of strings from an input file
void help::create_vector(const std::string& file_name, std::vector<std::vector<std::string>>& v)
{
  //Read the input file lines. Each line is stored as a vector of string and finally stored in a vector of rows
  std::ifstream in(file_name);
  if(in)
  {
    std::string line;
    while(getline(in, line))
    { //read the current row
        std::stringstream sep(line);
        v.push_back(std::vector<std::string>()); //insert in v an empty row to be filled
        std::string string_name;
        while (getline(sep, string_name, ','))
        { // read words comma separated
            v.back().push_back(string_name);
        }
    }
  }
}

void help::add_data_dir(std::string& name)
{
  std::string dir;
  std::ifstream ifs{"config.txt"};
  ifs >> dir;
  name = dir + name;
}

void help::add_lua_dir(std::string& name)
{
  // the extesion .lua is erased because we will need to add a suffix
  name.erase(name.end() - 4, name.end());
  std::string dir;
  std::ifstream ifs2{"config.txt"};
  ifs2 >> dir >> dir >> dir;
  name = dir + name;
}

// get the application configuration file name
void help::add_config_file(std::string& name){
  std::string cfg_file_name;
  std::ifstream ifs2{"config.txt"};
  ifs2 >> cfg_file_name >> cfg_file_name >> cfg_file_name >> cfg_file_name;
  name = cfg_file_name;

}



std::string help::get_dagsim_command(const std::string& name)
{
  std::string com;
  std::ifstream ifs{"config.txt"};
  ifs >> com >> com;
  // select the correct number from the output of Dagsim
  com += "dagsim.sh " + name + "_mod.lua 2>&1|sed -n 1,1p|awk '{print $3}' > result.txt";
  return com;
}

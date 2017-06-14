#ifndef _CREATE_APP_HPP_
#define _CREATE_APP_HPP_

#include "Application.hpp"
#include "Helper.hpp"
#include "Job.hpp"
#include "Stage.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <list>

namespace c_app
{
  //Create application object from input file
  Application create_app(const std::string& name_of_file);

}

#endif

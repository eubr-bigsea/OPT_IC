// Copyright 2017 <Biagio Festa>

/*
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

#include <iostream>
#include <opt_common/Application.hpp>
#include <opt_common/CommandLineParser.hpp>
#include <string>
#include "Create_object.hpp"

int main(int argc, char** argv) {
  using opt_common::CommandLineParser;
  using opt_common::Application;

  const std::string DefaultConfigFile = "config.txt";

  // Parse command line
  CommandLineParser::CommandLineOptions cl_options;
  try {
    cl_options = CommandLineParser::parse_command_line(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << "Command Line Parsing Error.\n"
              << "Internal Error: " << err.what() << "\n"
              << "Usage:\n"
              << argv[0]
              << " input_file -(f|F|b|B) [--no-ml] [-c CONFIG_FILE]\n";
    return -1;
  }

  const std::string config_namefile =
      (cl_options.config_file != "" ? cl_options.config_file
                                    : DefaultConfigFile);

  // Create application
  auto application =
      Application::create_application(cl_options.name_of_file, config_namefile);

  // Create optimize method and run it
  create_object::create_obj(cl_options.optimize_method, application,
                            cl_options.no_ml);

  return 0;
}

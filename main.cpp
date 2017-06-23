/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli
Copyright 2017 Biagio Festa <biagio.festa@gmail.com>

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

#include "Create_application.hpp"
#include "Create_object.hpp"
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
  const auto cmd_options = create_object::parse_command_line(argc, argv);

  // we create an application and initialize it
  Application app;
  app = c_app::create_app(cmd_options.name_of_file);

  // we create on object with the method and run it
  create_object::create_obj(cmd_options.optimize_method, app,
                            cmd_options.no_ml);

  return 0;
}

#include "Create_application.hpp"
#include "Create_object.hpp"
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
  std::string name_of_file;
  std::string method;

  // name_of_file and method are set with the correct strings extracted from argv
  create_object::set_arguments(name_of_file, method, argc, argv);

  // we create an application and initialize it
  Application app;
  app = c_app::create_app(name_of_file);

  // we create on object with the method and run it
  create_object::create_obj(method, app);

  return 0;
}

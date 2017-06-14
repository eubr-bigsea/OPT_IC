/*
Copyright 2017 Danilo Ardagna

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

#include "InfrastructureConfiguration.hpp"

unsigned InfrastructureConfiguration::get_n_containers (unsigned n_required_executors_cores) const{


    unsigned  required_executors =  ceil((double)n_required_executors_cores/executor_cores);

    /* Debug Danilo
    double a=(double)required_executors * executor_memory/container_memory;

    double b = (double) required_executors * executor_cores/containter_cores;
*/
    //std::cout << a << " " << b << std::endl;

    unsigned required_containers =  ceil(fmax((double)required_executors * executor_memory/container_memory,(double) required_executors * executor_cores/containter_cores));

    return required_containers;

}

/*
InfrastructureConfiguration::InfrastructureConfiguration (const InfrastructureConfiguration &ic) {
    container_memory= ic.getContainer_memory();
    executor_memory=ic.getExecutor_memory();
    containter_cores =ic.getContainter_cores();
    executor_cores =ic.getExecutor_cores();
}
*/


void InfrastructureConfiguration::print() const{

    std::cout << '\n'
              << container_memory << " "
              <<  executor_memory << " "
              << containter_cores << " "
              << executor_cores <<std::endl;
}



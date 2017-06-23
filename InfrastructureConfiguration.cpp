//
// Created by Danilo Ardagna on 05/04/2017.
//

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



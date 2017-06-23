//
// Created by Danilo Ardagna on 17/04/2017.
//

#include "MachineLearningModel.hpp"
#include "Helper.hpp"

void MachineLearningModel::print() const{

    std::cout << '\n'
              << chi_0 << " "
              <<  chi_c <<std::endl;
}

double MachineLearningModel::evaluateModel(unsigned n) const {

    //int n_containers=n/ic.getContainter_cores();

    return chi_0+chi_c/n;
}

unsigned MachineLearningModel::initial_core_numbers(const InfrastructureConfiguration & ic,  help::time_instant deadline) const {

    //double xi=fmin((double)ic.getContainer_memory()/ic.getExecutor_memory(), (double) ic.getContainter_cores()/ic.getExecutor_cores());
    /* Old Version
    double n_containers= fmin(chi_c/(deadline-chi_0),1);

    double n_cores= ic.getExecutor_cores()  * ceil(n_containers);
    */
    double n_cores= fmax(chi_c/(deadline-chi_0),ic.getContainter_cores());

    //double n_cores= ic.getExecutor_cores()  * ceil(n_containers);

    std::cout << "\n" << "Initial cores number: " <<n_cores << std::endl;

    return n_cores;
}


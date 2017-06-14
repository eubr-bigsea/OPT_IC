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


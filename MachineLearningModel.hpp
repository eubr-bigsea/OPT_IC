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

#ifndef VESCOVINIZANINELLI_MACHINELEARNINGMODEL_H
#define VESCOVINIZANINELLI_MACHINELEARNINGMODEL_H

#include "InfrastructureConfiguration.hpp"
//#include "Job.hpp"
#include "Helper.hpp"



#include <iostream>
#include <cmath>


class MachineLearningModel {
    double chi_0;
    double chi_c;

public:
    MachineLearningModel(double chi_0=0.1, double chi_c=0.1):
    chi_0(chi_0),chi_c(chi_c){}

    //returns job execution time prediction for a given number of cores
    double evaluateModel(unsigned n) const;

    //determines the initial number of cores, given the infrastrucutre configuration and deadline
    unsigned initial_core_numbers(const InfrastructureConfiguration & ic, help::time_instant deadline) const;


    void print() const;

    double get_chi_0() const {
        return chi_0;
    }

    double get_chi_c() const {
        return chi_c;
    }

    void set_chi_0(double chi_0) {
        MachineLearningModel::chi_0 = chi_0;
    }

    void set_chi_c(double chi_c) {
        MachineLearningModel::chi_c = chi_c;
    }
};


#endif //VESCOVINIZANINELLI_MACHINELEARNINGMODEL_H

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

#ifndef _INFRASTRUCTURECONFIGURATION_HPP_
#define _INFRASTRUCTURECONFIGURATION_HPP_

#include <cmath>
#include <iostream>


class InfrastructureConfiguration {

public:
    float getContainer_memory() const {
        return container_memory;
    }

    float getExecutor_memory() const {
        return executor_memory;
    }

    int getContainter_cores() const {
        return containter_cores;
    }

    int getExecutor_cores() const {
        return executor_cores;
    }

    void print() const;


    InfrastructureConfiguration(float container_memory = 4, float executor_memory = 2, unsigned container_cores = 2 , unsigned executor_cores = 1)
            : container_memory(container_memory), executor_memory(executor_memory), containter_cores(container_cores),
              executor_cores(executor_cores) {}

    unsigned  get_n_containers (unsigned n_required_executors_cores) const;

private:
    float container_memory;
    float executor_memory;
    unsigned  containter_cores;
    unsigned executor_cores;
};

#endif

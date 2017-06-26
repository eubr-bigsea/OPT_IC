/*
Copyright 2017 Andrea Vescovini
Copyright 2017 Sara Zaninelli
Copyright 2017 Biagio Festa <info@biagiofesta.it>

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

#ifndef _CREATE_OBJ_HPP_
#define _CREATE_OBJ_HPP_

#include <opt_common/Application.hpp>
#include <opt_common/CommandLineParser.hpp>
#include <string>
#include "Fast_bisection_optimization.hpp"
#include "Fast_optimization.hpp"
#include "Time_meas.hpp"

namespace create_object {
// this is the function that starts any kind of optimization (simple, fast,
// fast-bisection)
unsigned start_optimization(Abstract_optimization& opt, bool no_ml);

// this function creates an object of Fast/Fast_Bisection_optimization and
// starts the optimization
void create_obj(
    const opt_common::CommandLineParser::OptimizeMethod& optimize_method,
    opt_common::Application& app, bool no_ml);
}

#endif

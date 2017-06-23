/*
## Copyright 2017 Marco Gribaudo <marco.gribaudo@polimi.it>
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##     http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "matrix/Matrix.h"
#include "luaInterface.h"
#include "distributions.h"



double Rnd() {
// replace with Merseen-Twister
	return drand48();
}

void SetSeed(int seed) {
	srand48(seed);
}

void SetRandomSeed() {
	srand48(time(NULL));
}


void SetRandomSeedTh(int i, int n) {
	srand48(time(NULL)*n+i);
}

This code provides three algorithms to calculate the minimum number
of virtual machines that are necessary to perform the applications
within a given deadline. To calculate in a quite accurate way the
execution time we use the program Dagsim, provided by prof. Enrico
Barbierato and prof. Marco Gribaudo.

Simple_optimization increments or decrements by one the number of
virual machines until the execution time calculated with Dagsim time
is under the deadline.

Fast_optimization uses an approximation with an hyperbole to calculate
the minimum number of virual machines whose execution time should be
under the deadline, at every iteration a more accurate estimate is done
with Dagsim. At each iteration we verify if we are oscillatind and in
that case we replace the calculated nVM with the average of nmin and
nmax.

Fast_optimization_bisection is the same of Fast optimization,
but in case of oscillation we leave the hyperbole and we start with
the bisection method.
------------------------------------------------------------------
We have performed two test using the Makefile:

build_test_diff is a comparison test in which we verify that the
three methods return the same optimum value.

build_test_deadline is a way analyze how the number of iterations
change when the deadline decreases. It operates with Fast_optimization
and Fast_optimization_bisection.

-------------------------------------------------------------------
If you want to change the directories of the .csv files, .lua files
or Dagsim you have to modify config.txt:

first line: directory of the .csv files of app jobs stages and task
second line: directory of Dagsim
third line: directory if the .lua fila required by Dagsim

--------------------------------------------------------------------
How to run the program:

./Res_opt <app.txt> <methods>

--------------------------------------------------------------------
In the file app.txt you have to write:

name of the .csv file of app|jobs|stages|tasks|deadline

--------------------------------------------------------------------
With methods you select: 

Simple_optimization = s;
Fast_optimization = f;
Fast_optimization_bisection = b;

example: ./Res_opt app.txt f b s

--------------------------------------------------------------------
When you want to start the program with all the 3 methods using the
makefile you should write:

make ARGS=app.txt METH=fsb run
#!/usr/bin/env python2.7
import os
deadlines_min=100000
deadlines_max=1000000
deadline_step=100000

deadline = deadlines_min
os.remove('iterations.txt');
os.remove('containers.txt');
os.remove('time.txt');
while deadline<= deadlines_max:
	os.system('grep Iterations out'+str(deadline)+'>>iterations.txt')
	os.system('grep YARN out'+str(deadline)+'>>containers.txt')
	os.system('grep Elapsed out'+str(deadline)+'>>time.txt')   
	deadline= deadline + deadline_step

 

#!/usr/bin/env python2.7
from shutil import copyfile

import os

deadlines_min=100000
deadlines_max=1000000
deadline_step=100000

#application="app_P82"
application="app_D2"

application_name=application+".txt"
application_template_name=application_name+".template"

#start analysis
deadline = deadlines_min
while deadline<= deadlines_max:
	print deadline
	#os.system('echo ' +str(deadline))
	copyfile(application_template_name, application_name)
	#os.system('cp app_1.txt.template app_1.txt')
	command="sed -ie 's/@@deadline@@/"+str(deadline)+"/g' "+application_name
	os.system(command)
	os.system('cat '+application_name);
	os.system('./Res_opt ' + application_name + ' f > out'+str(deadline)) 
	deadline= deadline + deadline_step

 

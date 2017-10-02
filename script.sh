# Note that the deadline given in input and the deadline in CnfigAPp1.txt must be the same
if [ "$#" -ne 3 ]; then
    echo "./script.sh <appId> <dataset> <deadline>"
    exit -1
fi
#
# Dependencies: ~/wsi_config.xml
#
FILE=~/wsi_config.xml
if [ -f $FILE ]; then
	#
	# Get OPT_IC path
	#
	temp=$(cat ~/wsi_config.xml|grep RESOPT_HOME)
	OPT_IC_HOME=$(echo $temp| awk -v FS="(>|<)" '{print $3}')
	if [ -d $OPT_IC_HOME ]; then
                cd $OPT_IC_HOME
        else
                echo "Folder $OPT_IC_HOME does not exist."
                exit
        fi
	#
	# Get data logs path
	#
	temp=$(cat ~/wsi_config.xml|grep RESULTS_HOME)
	RESULTS_HOME=$(echo $temp| awk -v FS="(>|<)" '{print $3}')
	if [ ! -d $RESULTS_HOME ]; then
                echo "Folder $RESULTS_HOME does not exist."
                exit
        fi

	#
	#
	# Read the config.txt folder
	#
	LOCALDATA=$(head -1 $OPT_IC_HOME/config.txt)
	if [ -d $LOCALDATA ]; then
		cd $LOCALDATA
	else
   		echo "$LOCALDATA folder does not exist."
		exit
	fi
	
	#
	# Determine the right folder (in the middle)
	#
	cd $RESULTS_HOME
	# ls -d *$2*/$1 > /tmp/tmp.txt
	ls -d *$2* > /tmp/tmp.txt
	if [ $? -ne 0 ]; then
    		echo dataset $2 is not a valid input parameter
		exit
	fi
	NUM_FOLDERS=$(ls -d *$2*/$1|wc -l)
	if [ $? -ne 0 ]; then
                echo query $1 is not a valid input parameter
                exit
        fi
	DIR_POS=$(expr $NUM_FOLDERS / 2)
	CMD1="sed -n '$DIR_POS"
	CMD2="p' /tmp/tmp.txt"
	CMD=$CMD1$CMD2
	#
	# Middle folder's name
	#
	DIR=$(eval ${CMD})
	#
	# Generate 'on-the-fly' app1.txt
	#
	cd $OPT_IC_HOME
	#
	# Determine local LUA folder name
	#
	LUA=$(sed -n '3p' $OPT_IC_HOME/config.txt)
	cd $RESULTS_HOME/$DIR/$1/logs
	#
	# Retrieve the lua file for the fist subfolder
	#
	cd $(ls -d */|head -n 1)
#pwd
	LUA_FOLDER=$PWD
	LUA_FILENAME=$(ls *.lua)
	CSV_FILES=$(ls *.csv)
	#
	# Copy the ConfigApp_1.txt lua and csv files
	#
	cp $OPT_IC_HOME/ConfigApp_1.txt $LOCALDATA
	cp $LUA_FILENAME $LUA
	cp $CSV_FILES $LOCALDATA
	if [ ! -f $LOCALDATA/ConfigApp_1.txt ]; then
                echo "$LOCALDATA/ConfigApp_1.txt file does not exist."
		pwd
                exit
        fi
	#cp ConfigApp_1.txt $LOCALDATA
	cd $LUA
	FILENAME=$(echo "${LUA_FILENAME%%.*}")
	LUA_BAK_FILENAME=$LUA_FOLDER/$FILENAME.bak
	if [ ! -f $LUA_FOLDER/$FILENAME.lua ]; then
                echo " $LUA_FOLDER/$FILENAME.lua file does not exist."
                pwd
                exit
        fi
	cp $LUA_FOLDER/$FILENAME.lua $LUA_BAK_FILENAME 
	echo $CSV_FILES' '$LUA_FILENAME' 'ConfigApp_1.txt' '$3 > $OPT_IC_HOME/app1.txt
	#
	# Prepare the lua file with place-holder
	#
	line=$(cat $LUA$LUA_FILENAME|grep "Nodes = ")
	sed -i "s/$line/Nodes = @@nodes@@;/g" $LUA$LUA_FILENAME
	#
	# Launch OPT_IC
	#
	cd $OPT_IC_HOME
	$OPT_IC_HOME/opt_ic app1.txt f > $OPT_IC_HOME/_out.txt
	#
	# Restore the original lua file
	#
	if [ -f $LUA_BAK_FILENAME ]; then
		mv $LUA_BAK_FILENAME $LUA_FOLDER/$LUA_FILENAME
	else 
		echo File $LUA_BAK_FILENAME not found.
	fi
	#
	# Extract requested information 
	output1=$(cat $OPT_IC_HOME/_out.txt|grep "Optimum Ncores using fast optimization:" | sed -n "s/^.*:\s*\(\S*\).*$/\1/p")
	output2=$(cat $OPT_IC_HOME/_out.txt|grep "N YARN containers (VMs):" | sed -n "s/^.*:\s*\(\S*\).*$/\1/p")
	echo $output1 $output2
else
   echo "FATAL ERROR: File $FILE does not exist."
fi

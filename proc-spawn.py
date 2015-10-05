####################################################################
####################################################################
###  															 ###
###  Author: Brad Stell											 ###
### 															 ###
###  Date: 10/2/2015											 ###
### 															 ###
###  Language: Python 2.7.10 | Anaconda 2.3.0					 ###
###																 ###
###	 Description: 												 ###
###  	This program calls the sorting algo program 'main.exe'	 ###
###		with various input sizes. It times the runtime 			 ###
###		of the program to make sure each iteration it does not 	 ###
###		exceed 2.5 hours per run (5 minutes max per one sort	 ###
###		iteration with each sort running 30 times for average	 ###
### 	case analysis).											 ###
###																 ###
####################################################################
####################################################################

from subprocess import call		# for starting external processes
import time						# for timing

##########################
### Run Insertion Sort ###

# Start with array size of 2
elms = 2;

# while the array size is less than 4,000,000
while elms < 4000000:
	
	# start the timmer
	start_time = time.time()
	
	# Call the sort program, read from 'nums.txt',
	# process 'elms' amount of numbers (doubles every time for 
	# increasing in log scale), with the insertion sort flag '-i'
	call(["main.exe", "nums.txt", str(elms), "-i"])
	
	# capture the elapsed time
	total_time = time.time() - start_time
	
	# make sure the elapsed time is not more than 9,000 seconds,
	# or 2.5 hours (5 min * 60 = 300 seconds per run * 30 runs
	# per iteration = 9,000 seconds)
	if total_time > 9000:
		break
	
	# increase elms by 2 for logarithmic growth processing
	elms *= 2


############################################################################
############################   					############################
##########														  ##########
######																  ######
### The below code does the same as above with different sort algo flags ###
#																		   #
############################################################################


##########################
### Run Selection Sort ###
elms = 1048576;

#while elms < 4000000:
	
	start_time = time.time()
	call(["main.exe", "nums.txt", str(elms), "-s"])
	total_time = time.time() - start_time
	
	if total_time > 9000:
		break
	
	elms *= 2


elms = 2;


#######################
### Run Bubble Sort ###
while elms < 4000000:
	
	start_time = time.time()
	call(["main.exe", "nums.txt", str(elms), "-b"])
	total_time = time.time() - start_time
	
	if total_time > 9000:
		break
	
	elms *= 2


elms = 2;


############################
### Run Brute Force Sort ###
while elms < 4000000:
	
	start_time = time.time()
	call(["main.exe", "nums.txt", str(elms), "-bf"])
	total_time = time.time() - start_time
	
	if total_time > 9000:
		break
	
	elms *= 2
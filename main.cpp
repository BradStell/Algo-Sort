//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//	Author: Brad Stell																	//
//																						//
//	Date: 9/24/2015																		//
//																						//
//	Language: c++																		//
//																						//
//	Description:																		//
//		This program accepts 3 parameters from the command line:						//
//			1) The name of a file to read numbers from									//
//			2) The number of elements to proccess from that file						//
//			3) A flag that dictates which sorting alorithm to use:						//
//				-bf for Brute Force sorting												//
//				-i for Insertion sort													//
//				-b for Bubble sort														//
//				-s for selection sort													//
//																						//
//				example for selection sort with 1,000 elements:							//
//					  main.exe instance.txt 1000 -s										//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include "sort.h"


//////////////////////////////
/// Function Declarations ///

/* Calculates the average of an array */
double getAverage(clock_t *avgArr);

/* Calculates the standard deviation of the 30 times calculated for each algo */
double getStdDev(clock_t * avgArr, double avg);

/*
	Main method:
		checks for proper program instantiation
		calls appropriate sorting method based on <sort algo> flag 

		Error checking:
			Makes sure program was called correctly
			Makes sure valid flag was used
			Makes sure number of elements to process does not exceed numbers in file
*/
int main(int argc, char *argv[])
{
	/////////////////////////////////////////////////////////////////////
	/// Display correct usage of program if instantiated incorrectly ///

	if (argc != 4)
	{
		std::cout << "\nUsage: " << argv[0] << " <file to open> <number of elements to process> <sort algo to run>\n\n"
			"<sort algo to run>\n\t-bf for brute force\n"
			"\t-i for insertion sort\n"
			"\t-b for bubble sort\n"
			"\t-s for selection sort\n\n"
			"Example\n\tFor selection sort with 1,000 elements:  main.exe instance.txt 1000 -s\n\n";
		return 0;
	}


	////////////////////////////////////////////////////
	/// Program execution if instantiated correctly ///

	/* Variables */
	int numElm = atoi(argv[2]);
	int *array = new int[numElm];
	std::ifstream file(argv[1]);


	/* Report and abort failed file open */
	if (!file.is_open())
	{
		std::cout << "\nFailed to open file. Check the spelling and try again.\n";
		return 0;
	}

	
	/* Populate the array from the file */
	std::string line;
	int num;
	for (int i = 0; i < numElm; i++)
	{
		getline(file, line);

		std::stringstream ss(line);
		ss >> num;
		array[i] = num;
	}


	/////////////////////////
	/// Call Brute Force ///
	if (strcmp(argv[3], "-bf") == 0)
	{
		std::cout << "Calling Brute Force with " << argv[2] << " elements\n\n";

		/* Run the algo 30 times and time it to get an average time */

		// Array to hold the 30 different times
		clock_t avgArr[30];

		for (int i = 0; i < 30; i++)
		{
			clock_t time = clock();
			Sort::BruteForce(array, 0, numElm);
			avgArr[i] = clock() - time;

			// Must repopulate array from file, or else the already sorted array will
			// be passed back into the function and it will drastically mess up the time.
			std::string line;
			int num;
			for (int i = 0; i < numElm; i++)
			{
				getline(file, line);

				std::stringstream ss(line);
				ss >> num;
				array[i] = num;
			}
		}

		// Get the average of the 30 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);

		std::ofstream fileOut("Time-Outputs.txt", std::ios::app);

		fileOut << "\n\t### Brute Force ###\n"
			 << "Array Size: " << numElm << std::endl
			 << "Average Time: " << avgTime << " cpu ticks" << std::endl
			 << "\t\t\t " << avgTime / CLOCKS_PER_SEC << " seconds" << std::endl
			 << "Standard Dev: " << stdDev << std::endl;

		fileOut.close();
	}

	////////////////////////////
	/// Call Insertion Sort ///
	else if (strcmp(argv[3], "-i") == 0)
	{
		std::cout << "Calling Insertion Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 30 times and time it to get an average time */

		// Array to hold the 30 different times
		clock_t avgArr[30];

		for (int i = 0; i < 30; i++)
		{
			clock_t time = clock();
			Sort::InsertionSort(array, numElm);
			avgArr[i] = clock() - time;

			// Must repopulate array from file, or else the already sorted array will
			// be passed back into the function and it will drastically mess up the time.
			std::string line;
			int num;
			for (int i = 0; i < numElm; i++)
			{
				getline(file, line);

				std::stringstream ss(line);
				ss >> num;
				array[i] = num;
			}
		}	

		// Get the average of the 30 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);

		std::ofstream fileOut("Time-Outputs.txt", std::ios::app);

		fileOut << "\n\t### Insertion Sort ###\n"
			 << "Array Size: " << numElm << std::endl
			 << "Average Time: " << avgTime << " cpu ticks" << std::endl
			 << "\t\t\t " << avgTime / CLOCKS_PER_SEC << " seconds" << std::endl
			 << "Standard Dev: " << stdDev << std::endl;

		fileOut.close();
	}

	/////////////////////////
	/// Call Bubble Sort ///
	else if (strcmp(argv[3], "-b") == 0)
	{
		std::cout << "Calling Bubble Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 30 times and time it to get an average time */

		// Array to hold the 30 different times
		clock_t avgArr[30];

		for (int i = 0; i < 30; i++)
		{
			clock_t time;
			Sort::BubbleSort(array, numElm);
			avgArr[i] = clock() - time;

			// Must repopulate array from file, or else the already sorted array will
			// be passed back into the function and it will drastically mess up the time.
			std::string line;
			int num;
			for (int i = 0; i < numElm; i++)
			{
				getline(file, line);

				std::stringstream ss(line);
				ss >> num;
				array[i] = num;
			}
		}

		// Get the average of the 30 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);		

		std::ofstream fileOut("Time-Outputs.txt", std::ios::app);

		fileOut << "\n\t### Bubble Sort ###\n"
			<< "Array Size: " << numElm << std::endl
			 << "Average Time: " << avgTime << " cpu ticks" << std::endl
			 << "\t\t\t " << avgTime / CLOCKS_PER_SEC << " seconds" << std::endl
			 << "Standard Dev: " << stdDev << std::endl;

		fileOut.close();
	}

	////////////////////////////
	/// Call Selection Sort ///
	else if (strcmp(argv[3], "-s") == 0)
	{
		std::cout << "Calling Selection Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 30 times and time it to get an average time */

		// Array to hold the 30 different times
		clock_t avgArr[30];

		for (int i = 0; i < 30; i++)
		{
			clock_t time;
			Sort::SelectionSort(array, numElm);
			avgArr[i] = clock() - time;

			// Must repopulate array from file, or else the already sorted array will
			// be passed back into the function and it will drastically mess up the time.
			std::string line;
			int num;
			for (int i = 0; i < numElm; i++)
			{
				getline(file, line);

				std::stringstream ss(line);
				ss >> num;
				array[i] = num;
			}
		}

		// Get the average of the 30 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);	

		std::ofstream fileOut("Time-Outputs.txt", std::ios::app);

		fileOut << "\n\t### Selection Sort ###\n"
			<< "Array Size: " << numElm << std::endl
			 << "Average Time: " << avgTime << " cpu ticks" << std::endl
			 << "\t\t\t " << avgTime / CLOCKS_PER_SEC << " seconds" << std::endl
			 << "Standard Dev: " << stdDev << std::endl;

		fileOut.close();
	}

	////////////////////////////////////
	/// Invalid sort algo flag used ///
	else
	{
		std::cout << "\n\nInvalid sort algo flag used.\nTerminating program...\n\n";
		return 0;
	}

	return 0;
}

double getAverage(clock_t *avgArr)
{
	double avg = 0;

	for (int i = 0; i < 30; i++)
		avg += avgArr[i];

	return avg / 30.0;
}

double getStdDev(clock_t *avgArr, double avg)
{
	double stdDev = 0;

	for (int i = 0; i < 30; i++)
		stdDev += pow((avgArr[i] - avg), 2);

	return sqrt((stdDev / 30.0));
}
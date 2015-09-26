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
#include <cstdlib>
#include <cmath>
#include "sort.h"


//////////////////////////////
/// Function Declarations ///

/* Read bytes from in-stream and place them in a buffer */
unsigned int FileRead(std::istream & is, std::vector <char> & buff);

/* Reades bytes from buffer and returns number of '\n' characters found */
unsigned int CountLines(const std::vector <char> & buff, int sz);

/* Calculates the average of an array */
double getAverage(clock_t *avgArr);

/* Calculates the standard deviation of the 10 times calculated for each algo */
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

	////////////		 Check number of elements in the file		///////////////////////////////////////////////////////////
	
	const int SZ = 1024 * 1024;		// 1MB buffer size
	std::vector <char> buff(SZ);	// Buffer for bytes read from file
	std::ifstream ifs("num.txt");	// File to open
	int size = 1;

	// Get number of lines in the file
	while (int cc = FileRead(ifs, buff)) {
		size += CountLines(buff, cc);
	}

	// Make sure the requested amount of elements to process does not exceed what is in the file
	if (numElm > size)
	{
		std::cout << "\n\nYou are trying to process more elements than are in the file.\nTerminating program.....\n\n";
		return 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

		/* Run the algo 10 times and time it to get an average time */

		// Array to hold the 10 different times
		clock_t avgArr[10];

		for (int i = 0; i < 10; i++)
		{
			clock_t time = clock();
			Sort::BruteForce(array, 0, numElm);
			avgArr[i] = clock() - time;
		}

		// Get the average of the 10 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);

		std::ofstream fileOut("Time-Outputs.txt");

		fileOut << "\t### Brute Force ###\n"
			 << "Average Time: " << avgTime << std::endl
			 << "Standard Dev: " << stdDev << std::endl;

		fileOut.close();
	}

	////////////////////////////
	/// Call Insertion Sort ///
	else if (strcmp(argv[3], "-i") == 0)
	{
		std::cout << "Calling Insertion Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 10 times and time it to get an average time */

		// Array to hold the 10 different times
		clock_t avgArr[10];

		for (int i = 0; i < 10; i++)
		{
			clock_t time = clock();
			Sort::InsertionSort(array, numElm);
			avgArr[i] = clock() - time;
		}		

		// Get the average of the 10 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);
	}

	/////////////////////////
	/// Call Bubble Sort ///
	else if (strcmp(argv[3], "-b") == 0)
	{
		std::cout << "Calling Bubble Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 10 times and time it to get an average time */

		// Array to hold the 10 different times
		clock_t avgArr[10];

		for (int i = 0; i < 10; i++)
		{
			clock_t time;
			Sort::BubbleSort(array, numElm);
			avgArr[i] = clock() - time;
		}

		// Get the average of the 10 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);		
	}

	////////////////////////////
	/// Call Selection Sort ///
	else if (strcmp(argv[3], "-s") == 0)
	{
		std::cout << "Calling Selection Sort with " << argv[2] << " elements\n\n";

		/* Run the algo 10 times and time it to get an average time */

		// Array to hold the 10 different times
		clock_t avgArr[10];

		for (int i = 0; i < 10; i++)
		{
			clock_t time;
			Sort::SelectionSort(array, numElm);
			avgArr[i] = clock() - time;
		}

		// Get the average of the 10 times
		double avgTime = getAverage(avgArr);

		// Get the standard deviation of those times
		double stdDev = getStdDev(avgArr, avgTime);		
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


/*
	This method accepts an instream and a vector buffer.
	It will read bytes from the instream and put them in the buffer in 1MB chuncks.
*/
unsigned int FileRead(std::istream & is, std::vector <char> & buff) {
	is.read(&buff[0], buff.size());
	return is.gcount();
}


/*
	This method receives the buffer and the byte count from the above method.
	It will count the number of newline characters and return how many were found,
	thus analogous to the number of elements in the file.
*/
unsigned int CountLines(const std::vector <char> & buff, int sz) {
	int newlines = 0;
	const char * p = &buff[0];
	for (int i = 0; i < sz; i++) {
		if (p[i] == '\n') {
			newlines++;
		}
	}
	return newlines;
}

double getAverage(clock_t *avgArr)
{
	double avg = 0;

	for (int i = 0; i < 10; i++)
		avg += avgArr[i];

	return avg / 10.0;
}

double getStdDev(clock_t *avgArr, double avg)
{
	double stdDev = 0;

	for (int i = 0; i < 10; i++)
		stdDev += pow((avgArr[i] - avg), 2);

	return sqrt((stdDev / 10));
}
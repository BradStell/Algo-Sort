#include <iostream>
#include <string.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "sort.h"


//////////////////////////////
/// Function Declarations ///
unsigned int FileRead(std::istream & is, std::vector <char> & buff);
unsigned int CountLines(const std::vector <char> & buff, int sz);



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


	// 1MB buffer size
	const int SZ = 1024 * 1024;
	std::vector <char> buff(SZ);
	std::ifstream ifs("num.txt");
	int size = 1;
	while (int cc = FileRead(ifs, buff)) {
		size += CountLines(buff, cc);
	}





	/* Variables */
	int numElm = atoi(argv[2]);
	int *array = new int[numElm];
	std::ifstream file(argv[1]);

	if (numElm > size)
	{
		std::cout << "\n\nYou are trying to process more elements than are in the file.\nTerminating program.....\n\n";
		return 0;
	}


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

		Sort::BruteForce(array, 0, numElm);
	}

	////////////////////////////
	/// Call Insertion Sort ///
	else if (strcmp(argv[3], "-i") == 0)
	{
		std::cout << "Calling Insertion Sort with " << argv[2] << " elements\n\n";

		Sort::InsertionSort(array, numElm);
	}

	/////////////////////////
	/// Call Bubble Sort ///
	else if (strcmp(argv[3], "-b") == 0)
	{
		std::cout << "Calling Bubble Sort with " << argv[2] << " elements\n\n";

		Sort::BubbleSort(array, numElm);
	}

	////////////////////////////
	/// Call Selection Sort ///
	else if (strcmp(argv[3], "-s") == 0)
	{
		std::cout << "Calling Selection Sort with " << argv[2] << " elements\n\n";

		Sort::SelectionSort(array, numElm);
	}

	else
	{
		std::cout << "\n\nInvalid sort algo flag used.\nTerminating program...\n\n";
		return 0;
	}

	return 0;
}

unsigned int FileRead(std::istream & is, std::vector <char> & buff) {
	is.read(&buff[0], buff.size());
	return is.gcount();
}

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
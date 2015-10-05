/*
	Author: Brad Stell

	Date: 10/4/2015

	Language: c++

	Description: Write random numbers to a file for array filling
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() 
{
	ofstream file;
	file.open("nums.txt");

	// 2100000 is the largest size processed by the program
	// Originally 134 million in size, (in the GB file size)
	// It was reduced after project for better size management
	for (int i = 0; i < 2100000; i++)
	{
		file << rand() << endl;
	}
	
	return 0;
}
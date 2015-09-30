#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() 
{
	ofstream file;
	file.open("nums.txt");
						//134217728 is the log2 number max before 138 mil
	for (int i = 0; i < 134217728; i++)
	{
		file << rand() << endl;
	}
	
	return 0;
}
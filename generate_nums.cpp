#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	ofstream file;
	file.open("nums.txt");
						
	for (int i = 0; i < 134217728; i++)
	{
		file << i << endl;
	}
	
	return 0;
}
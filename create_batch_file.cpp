#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream file("run.bat");
	
	unsigned long elms = 2;
	while (elms < 138000000)
	{
		file << "main.exe nums.txt " << elms << " -i\n";
		elms *= 2;
	}
	file << "\n";
	
	elms = 2;
	while (elms < 138000000)
	{
		file << "main.exe nums.txt " << elms << " -s\n";
		elms *= 2;
	}
	file << "\n";
	
	elms = 2;
	while (elms < 138000000)
	{
		file << "main.exe nums.txt " << elms << " -b\n";
		elms *= 2;
	}
	file << "\n";
	
	elms = 2;
	while (elms <= 16)
	{
		file << "main.exe nums.txt " << elms << " -bf\n";
		elms *= 2;
	}
	
	file.close();
	
	return 0;
}
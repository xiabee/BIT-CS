// MyCopy.cpp : Defines the entry point for the console application.
//

#include "fstream"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 2) {
		cout << "Bad command parameter!" << endl;
		exit(1);
	}

	string line;
	ifstream  sFile(argv[1]);
	ofstream  oFile(argv[2]);

	if (sFile.is_open() == false || sFile.is_open() == false)
	{
		cout << "Error while opening a file!" << endl;
		exit(2);
	}

	while (getline(sFile, line))   oFile << line << endl;
	return 0;
}


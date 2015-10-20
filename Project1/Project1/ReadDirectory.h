#include <dirent.h>// directory header
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
using namespace std;
#include <string>

#include <fstream>
using std::ifstream;
using std::ofstream;

class ReadDirectory
{
	private:
		ifstream inStream;
		ofstream outStream;
		string name;
		string fileName;
	public:
		ReadDirectory();
		ReadDirectory(string);
		void readDirectory();
		string getName();
		void readFile();
};

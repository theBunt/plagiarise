#include <dirent.h>// directory header
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
#include <vector>
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
		vector<string> filenames;    // declares a vector of to store the filenames
		//vector<CheckedForPlagerism> checkList;
	public:
		ReadDirectory();
		ReadDirectory(string);
		void readDirFilenames();
		string getName();
		void readFile();
		vector<string> getFileNames();
		
};

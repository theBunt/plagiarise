#include "ReadDirectory.h"
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
using namespace std;
#include <cstring>
#include <string>

ReadDirectory::ReadDirectory()
{
	name = "";
}

ReadDirectory::ReadDirectory(string id)
{
	name = id;
}

void ReadDirectory::readDirectory()
{
	// code taken from http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/
	//  *************************************************************************

	DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
	struct dirent *pent = NULL;
	string dirName = "F:/Year3/AlgorithmDataStructure/elapsedCA/";
	string word = "";
	cout << "Enter the full path and directory name:\t";
	cin >> word;
	dirName = dirName + word;
	//these next 2 lines of code convert the string to char const to enable it to reead by the open dir command 
	/*char *cstr = new char[dirName.length() + 1];
	strcpy(cstr, dirName.c_str());*/
	pdir = opendir(dirName.c_str()); // "." will refer to the current directory

	if (pdir == NULL) // if pdir wasn't initialised correctly
	{ // print an error message and exit the 
		cout << "\nERROR! pdir could not be initialised correctly";
		system("pause");
		exit(1); // exit the program, using 1 as the status (most common for a failed execution)
	} // end if

	string fileName = "";
	while (pent = readdir(pdir)) // while there is still something in the directory to list
	{
		if (pent == NULL) // if pent has not been initialised correctly

		{ // print an error message, and exit the program
			cout << "ERROR! pent could not be initialised correctly";
			exit(3);
		}
		
		// otherwise, it was initialised correctly. let's print it on the console:
		
		cout << pent->d_name << endl;
	}

	closedir(pdir);

	// *****************************************************************************
}

string ReadDirectory::getName()
{
	return name;
}

void ReadDirectory::readFile()
{
	inStream.open("F:/Year3/AlgorithmDataStructure/elapsedCA/Checker/HotdogStand.cpp");
	if (inStream.fail())
	{
		cout << "Input file opening failed.\n";
		system("pause");
		exit(1);
	}
	cout << "Extracting from file:";
	string word;
	while (!inStream.eof()) {
		inStream >> word;
		cout << word;
	}
}

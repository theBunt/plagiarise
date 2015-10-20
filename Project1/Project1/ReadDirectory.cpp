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

void ReadDirectory::readDirFilenames()
{
	// code taken from http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/
	//  *************************************************************************

	DIR *pdir = NULL; // remember, it's good practice to initialise a pointer to NULL!
	struct dirent *pent = NULL;
	name = "F:/Year3/AlgorithmDataStructure/elapsedCA/";//hardcode for convenience, change to what suits!!
	string word = "";
	cout << "Enter the full path and directory name:\t";
	cin >> word;
	name = name + word;
	//these next 2 lines of code convert the string to char const to enable it to reead by the open dir command 
	/*char *cstr = new char[name.length() + 1];
	strcpy(cstr, name.c_str());*/
	pdir = opendir(name.c_str()); // "." will refer to the current directory

	if (pdir == NULL) // if pdir wasn't initialised correctly
	{ // print an error message and exit the 
		cout << "\nERROR! pdir could not be initialised correctly";
		system("pause");
		exit(1); // exit the program, using 1 as the status (most common for a failed execution)
	} // end if

	string fName = "";
	while (pent = readdir(pdir)) // while there is still something in the directory to list
	{
		if (pent == NULL) // if pent has not been initialised correctly

		{ // print an error message, and exit the program
			cout << "ERROR! pent could not be initialised correctly";
			exit(3);
		}

		// otherwise, it was initialised correctly. let's print it on the console:

		else if (pent->d_name[0] != '.')
		{
			string temp = name;
			fName = pent->d_name;
			temp = name + "/" + fName;
			filenames.push_back(temp);
		}
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
	//this loop transverses the vector storing the filenames and inputs them 
	for (size_t i = 0; i < filenames.size(); i++)
	{
		//PlageriseCount c1
		inStream.open(filenames[i]);
		if (inStream.fail())
		{
			cout << "\nInput file opening failed.\n";
			system("pause");
			exit(1);
		}
		cout << "\n******************\nExtracting from file: " << filenames[i] << endl;
		string word;
		while (!inStream.eof()) {
			inStream >> word;
			/*if (word == "for" || word == "while")
				c1.assessWord(word);*/
			cout << word << " ";
		}
		//make sure to close the instream before looping around and trying to read the next file
		inStream.close();
			
	}
}

vector<string> ReadDirectory::getFileNames()
{
	return filenames;
}



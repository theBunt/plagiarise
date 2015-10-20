#include <dirent.h>// directory header
#include <stdio.h> // printf()
#include <stdlib.h> // exit()
#include <iostream>
using namespace std;
#include <string>
#include "ReadDirectory.h"
#include <vector>



int main() // entry point of the program
{
	ReadDirectory readDir("Example");
	cout << readDir.getName() << endl;
	readDir.readDirFilenames();
	//readDir.readFile();
	vector<string> fNames = readDir.getFileNames();
	for (int i = 0; i < fNames.size(); i++) {
		cout << i+1 << ". " << fNames[i] << endl;
	}
	readDir.readFile();
	system("pause");

		return 0; // everything went OK

}





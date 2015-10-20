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
	readDir.readDirectory();
	//readDir.readFile();
	system("pause");

		return 0; // everything went OK

}





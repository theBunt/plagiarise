#pragma once
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

class FileCheck 
{
private:
	int fileSize;
	int wordCount;
	int itterativeCount;
	int selectionCount;
	int lineCount;
	string name;

public:
	void assesWordCount();
	void
};
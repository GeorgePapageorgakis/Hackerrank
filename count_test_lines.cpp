// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

unsigned count_flines(ifstream & filename) {
	return count(istreambuf_iterator<char>(filename), istreambuf_iterator<char>(), '\n') + 1;
}

int main() {
	ifstream ifile("inputfile03.txt");
	if (ifile.is_open() && ifile.good())
		cout << count_flines(ifile);
	ifile.close();

	//getchar();
	return 0;
}

#include <iostream>
#include <ctime>
#include <string>
#include "Module.h"

#include <fstream>

using namespace std;

const string PATH = "chemistry.txt";
ifstream inFile(PATH);
ofstream outFile;

int main() {
	string line;

	if (!inFile) {
		cout << "Could not open file";
		return 0;
	}
	
	outFile = read_formulas(inFile);

	system("pause");

	return 1;
}
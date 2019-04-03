#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Elem {
	string data;
	Elem * next;
};

struct List {
	Elem *top;

	List(void) :top(NULL) {}
};

void push(List &, const string);
bool pop(List &, string &);
bool getTop(List &, string &);

ofstream read_formulas(ifstream &inFile);
bool is_parenthese(char symbol);
bool is_closing(char symbol);
void read_formula(string line, ofstream &outFile);
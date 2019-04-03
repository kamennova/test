#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "Module.h"

using namespace std;

void push(List &s, const string x) {
	Elem *temp = new Elem;
	temp->data = x;
	temp->next = s.top;
	s.top = temp;
}

bool pop(List &s, string &out) {
	if (!s.top) {
		return false;
	}

	out = s.top->data;

	if (!s.top->next) {
		delete s.top;
		s.top = NULL;
		return true;
	}

	Elem *del = s.top;
	s.top = s.top->next;
	delete del;
	return true;
}

bool getTop(List &s, string &top) {
	if (s.top == NULL) {
		cout << "List is empty" << endl;
		return false;
	}

	top = s.top->data;
	return true;
}

//---

ofstream read_formulas(ifstream &inFile) {
	ofstream outFile("formulas.txt");
	string line;
	while (getline(inFile, line)){
		read_formula(line, outFile);
	}

	return outFile;
}

bool is_parenthese(char symbol) {
	if (symbol == '[' || symbol == ']' ||
		symbol == '(' || symbol == ')' ||
		symbol == '{' || symbol == '}') 
		return true;	

	return false;
}

bool is_closing(char symbol) {
	if (symbol == ']' || symbol == ')' || symbol == '}') return true;
	return false;
}

void read_formula(string line, ofstream &outFile) {
	int len = line.size();
	List Indexes;
	List Elem;

	for (int i = 0; i < len; i++) {
		// parentheses
		if (is_parenthese(line[i])) {
			continue;
		} 
			
		if (__ascii_isalpha(line[i])) {
			if (isupper(line[i])) {
				string elem;
				elem += line[i];
				i++;
				while (__ascii_isalpha(line[i]) && !isupper(line[i])) {
					elem += line[i];
					i++;
				}

				if (!isdigit(line[i])) {
					push(Indexes, "1");
				}
				
				i--;
				push(Elem, elem);
			}
		}
		
		if(isdigit(line[i])) {
			string index;

			while (isdigit(line[i])) {
				index += line[i];
				i++;
			}
			i--;
	
			//int index_num = index;
			push(Indexes, index);
			//cout << index;
		}

		//cout << endl;
	}

	string output;
	string out_elem;
	string out_index;

	while (pop(Indexes, out_index)) {
		pop(Elem, out_elem);
		output += out_elem + ": " + out_index + ", ";
	}

	cout << output << endl;

	outFile << output << "\n";
}
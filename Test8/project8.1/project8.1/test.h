#pragma once
#ifndef test_h
#define test_h
#include<fstream>
using namespace std;
void fio();
int ReadFiletoVec(const string& fileName, vector<string>& vec);
istream& func(ifstream& is);
bool valid(const string& str);
string format(const string& str);

struct PersonInfo {
	string name;
	vector<string> phones;
};
#endif // !1

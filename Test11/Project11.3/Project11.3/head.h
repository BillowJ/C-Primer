#pragma once
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>//getline
using namespace std;

map<string, string> build_Map(ifstream& map_file) {
	map<string, string> trans_map;//保存转换规则
	string key, value;
	while(map_file >> key && getline(map_file, value))
		if (value.size() > 1) {
			trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
		}
		else {
			throw runtime_error("no rule for " + key);
		}
	return trans_map;
}

const string& tansform(const string& s, const map<string, string>& m) {
	auto map_i = m.find(s);
	if (map_i != m.cend()) {
		return map_i->second;
	}
	else {
		return s;
	}
}

void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = build_Map(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) firstword = false;
			else std::cout << " ";
			cout << tansform(word, trans_map);
		}
		cout << endl;
	}
}

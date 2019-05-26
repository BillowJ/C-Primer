// Project11.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<set>
#include<map>
#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;
void ex11_4(map<string, size_t>& word_count) {
	
	string words;
	while (cin >> words) {
		for (auto& w : words) {
			w = tolower(w);
		}
		//remove的原理是移动
		words.erase(remove_if(words.begin(), words.end(), ispunct), words.end());
		++word_count[words];
	}
	for (auto& w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time ") << endl;
	}

}
int main()
{
	//单词计数器
	
	map<string, size_t> word_count;
	/*
	string words;
	while (cin >> words) {
		++word_count[words];
	}
	for (auto& w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time ") << endl;
	}*/
//	ex11_4(word_count);

	set<string> exclude = { " ", " ", " ", " ", " ", " ", "", " " };
	map<string, string> authors = { {"Joyce", "James"},
									{"Austen", "Jane"},
									{"Dickens", "Charles"} };
	//11.7
	map<string, vector<string>> familiy;
	string lastName, chldName;
	while ([&]() -> bool {
		std::cout << "Please enter last name:\n";

		return std::cin >> lastName && lastName != "@q";
		}()) {
		cout << " please input the chldName: " << endl;
		while (cin >> chldName) {
			familiy[lastName].push_back(chldName);
		}
	}
	for (auto e : familiy) {
		cout << e.first << " : \n";
		for (auto i : e.second) {
			cout << i << " ";
			cout << " \n";
		}
	}

}

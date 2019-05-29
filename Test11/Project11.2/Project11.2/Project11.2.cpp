// Project11.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include<set>//mutilset
#include<map>//multimap
#include<list>
#include<vector>
#include<utility>//pair
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	//11.23
/*	multimap<string, string> families;
	for (string last_name, first_name; cin >> last_name >> first_name; families.emplace(last_name, first_name));
	for (const auto& i : families)
		cout << i.second << " " << i.first << endl;*/
	vector<int> v;
//	v[0] = 1; 无法进行操作
//	for (const auto& e : v) std::cout << e << "\n";

	//! ex11.26
	std::map<int, std::string> map = { {1, "ss"}, {2, "sz"} };

	std::map<int, std::string>::key_type type_to_subscript = 1;
	//! that is, int.

	std::map<int, std::string>::mapped_type type_to_return =
		map[type_to_subscript];
	//! that is, std::string

	set<int> iset = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	if(iset.find(1) == iset.end()) cout << " not in set" << endl;

	//11.31
	multimap<string, string> author = { {"billow", "a"}, {"billowj", "b"} };
	for (auto iter = author.find("billow");
		iter != author.end() && iter->first == "billow";) {
		if (iter->second == "a")
			iter = author.erase(iter);
		else ++iter;
	}

	for (auto& i : author) {
		cout << i.first << " " << i.second << endl;
	}
	//11.32
	std::multimap<string, string> authors{
		{"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
		{"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"} };
	std::map<string, std::multiset<string>> order_authors;
	for (const auto& author : authors)
		order_authors[author.first].insert(author.second);
	for (const auto& author : order_authors) {
		std::cout << author.first << ": ";
		for (const auto& work : author.second) std::cout << work << " ";
		std::cout << std::endl;
		}
}

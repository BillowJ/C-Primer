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
	multimap<string, string> families;
	for (string last_name, first_name; cin >> last_name >> first_name; families.emplace(last_name, first_name));
	for (const auto& i : families)
		cout << i.second << " " << i.first << endl;
}

// Project11.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<set>//mutilset
#include<map>//multimap
#include<list>
#include<vector>
#include <iostream>
#include<algorithm>
#include<utility>//pair
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

//11.14 last name = 姓 first name = 名
class Families {
public:
	using child = pair<string, string>;//孩子的名(first name)和生日
	using children = vector<child>;
	using Data = map<string, children>;//家长(姓 last name) 和 孩子信息
	void add(string const& lastName, string const& firstName, string birthday) {
		_data[lastName].push_back(make_pair(firstName, birthday));//实际上是操作children这个vector容器
	}
	ostream& print(std::ostream& os) const
	{
		if (_data.empty()) return os << "No data right now." << endl;

		for (const auto& pair : _data) {
			os << pair.first << ":\n";
			for (const auto& child : pair.second)
				os << child.first << " " << child.second << endl;
			os << endl;
		}
		return os;
	}
private:
	Data _data;
};

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
/*	map<string, vector<string>> familiy;
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
	*/
	//11.9
	//行号保存为size_t类型
	map<string, list<size_t>> word_line;
	//11.10
	map<vector<int>::iterator, int> m;
	map<list<int>::iterator, int> m1;
	//11.11
	/*
	使用using 或者 typedef
	using compareType = bool (*)(const Sales_data& lhs, const Sales_data& rhs);
    // typedef bool(*compareType)(const Sales_data &lhs, const Sales_data &rhs);
    std::multiset<Sales_data, compareType> bookstore(compareIsbn);
	*/
	
	vector<pair<string, int>> vec;
	string str;
	int i;
/*	while (cin >> str >> i) {
		vec.push_back(make_pair(str, i));
		//vec.push_back(pair<string, int>(str, i));
		//vec.push_back({ st, i });
		//vec.emplace_back((str, i));
	}*/
	//11.14 test
	Families families;
    string message = "Please enter last name, first name and birthday";
    for (string l, f, b; cout << message << endl, cin >> l >> f >> b;
         families.add(l, f, b));
    families.print(cout << "Current data:" << endl);

    return 0;
	
}

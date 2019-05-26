// Project9.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include<vector>
#include<string>
#include<forward_list>
#include<fstream>
#include<array>
using namespace std;
//ex9.43
void Replace(string& s, const string& oldVal, const string& newVal) {
	for (auto beg = s.begin(); distance(beg, s.end()) >= distance(oldVal.begin(), oldVal.end());) {
		if (string{ beg, beg + oldVal.size() } == oldVal) {
			beg = s.erase(beg, beg + oldVal.size());
			beg = s.insert(beg, newVal.cbegin(), newVal.cend());
			advance(beg, newVal.size());
		}
		else {
			++beg;
		}
	}
}
//9.44
/*void Replace(string& s, const string& oldVal, const string& newVal) {
	for (string::size_type i = 0; i != s.size(); ++i) {
		if (s.substr(i, oldVal.size()) == oldVal) {
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size() - 1;//下标从0开始
		}
	}
}*/

inline std::string pre_suffix(const std::string& name, const std::string& pre,
	const std::string& su)
{
	auto ret = name;
	ret.insert(ret.begin(), pre.begin(), pre.end());
	ret.append(su);
//	ret.insert(0, pre);
//	ret.insert(ret.size(), su);

	return ret;
}

struct Date {
public:
//	Date() = default; 不可以存在 因为构造函数已有默认值 str = "";
	explicit Date(const string& str = "");
	void Print();
	unsigned int year = 1970;
	unsigned int month = 1;
	unsigned int day = 1;
private:
	array<string, 12> month_names{ "Jan", "Feb", "Mar", "Apr", "May", "Jun",
											"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	unsigned MonthFromName(const string& str);
};

Date::Date(const string& str) {
	if (str.empty()) return;
	string delimiter{ " ,/" };//三个字符
	auto month_day_delim_pos = str.find_first_of(delimiter);
	if (month_day_delim_pos == string::npos) {
		throw std::invalid_argument("this format is not supported now.");
	}
	month = MonthFromName(str.substr(0, month_day_delim_pos));
	auto day_year_delim_pos = str.find_first_of(delimiter, month_day_delim_pos + 1);
	auto day_len = day_year_delim_pos - month_day_delim_pos - 1;
	day = stoi(str.substr(month_day_delim_pos + 1, day_len));
	year = stoi(str.substr(day_year_delim_pos + 1));
}

unsigned Date::MonthFromName(const string& str) {
	if (str.empty()) return 0;
	if (isdigit(str[0])) return stoi(str);
	for (auto i = 0; i != 12; ++i) {
		if (str.find(month_names[i]) != string::npos) return i + 1;//返回对应月份的数值形式
	}
	return 0;
}

void Date::Print()
{
	std::cout << year << "-" << month << "-" << day << "\n";
}

int main()
{
	int a = 42;
	string s = to_string(a);
	double d = stod(s);
	vector<int> v1 = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int> fl = { 0,1,2,3,4,5,6,7,8,9 };

/*	auto curr = fl.begin(), prev = fl.before_begin();
	while (curr != fl.end()) {
		if (*curr % 2) {
			curr = fl.insert_after(prev, *curr);
			//forword_list 插入删除并不会使其迭代器失效
			advance(curr, 2);
			advance(prev, 2);
		}
		else {
			curr = fl.erase_after(prev);
		}
	}
	for (auto& iter : fl) cout << iter << " ";
	return 0;*/
/*	int words;
	while (cin >> words) {
		v1.push_back(words);
		cout << v1.capacity() << "\n";
	}
	return 0;*/
/*	string str ("ab2c3d7R1E3");
	string numbers{ "0123456789" };
	string::size_type pos = 0;
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	while ((pos = str.find_first_not_of(numbers,pos)) != string::npos){
		cout << "find alphabet at index " << pos
			<< " element is " << str[pos] << endl;
		++pos;
	}*/
/*	ifstream ifs("D:/Dir_C++/Test9/Project9.3/Project9.3/words.txt");
	if (!ifs) return -1;
	string long_words;
	for (string words; ifs >> words;) {
		if (words.find_last_not_of("aceimnorsuvwxz") == string::npos &&
			words.size() > long_words.size())
			long_words = words;
	}
	cout << long_words << endl;
	return 0;*/
	{ //  default case
		auto date = Date();
		date.Print();
	}
	{ //  case 0: January 1, 1900
		auto date = Date("January 1, 1900");
		date.Print();
	}
	{ //  case 1: 1/1/1900
		auto date = Date("1/1/1900");
		date.Print();
	}
	{ //  case 2: Jan 1, 1900
		auto date = Date("Jan 1, 1900");
		date.Print();
	}
}



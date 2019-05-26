// Project10.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//泛型算法
#include"head.h"
using namespace std;

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

bool hasFiveWords(const string& s) {
	return s.size() >= 5;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);

	stable_sort(words.begin(), words.end(),
		[sz](const string & a) {
			return a.size() >= sz; });

	auto wc = find_if(words.begin(), words.end(),
		[sz](const string & a) {
			return a.size() >= sz;
		});

	//计算符合条件的元素数量并利用for_each 打印
	auto count = words.end() - wc;
	for_each(wc, words.end(),
		[](const string & s) {
			cout << s << " ";
		});

	cout << endl;
}

void biggiesNew(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);

	stable_sort(words.begin(), words.end(),
		[sz](const string & a) {
			return a.size() >= sz; });

	auto wc = partition(words.begin(), words.end(),
		[sz](const string & a) {
			return a.size() < sz;
		});

	//计算符合条件的元素数量并利用for_each 打印
	auto count = words.end() - wc;
	for_each(wc, words.end(),
		[](const string & s) {
			cout << s << " ";
		});

	cout << endl;
}

int main()
{	
	vector<int> vec = { 1,2,3,4,32,52,52,34,2,12 };
	cout << "ex 10.1 : \" \" " << count(vec.cbegin(), vec.cend(), 52) << endl;
	list<string> vec1 = { "sadas", "asdasd", "adsa" };
	cout << "ex 10.2 : " << count(vec1.cbegin(), vec1.cend(), "adsad") << endl;
	cout << " sum : " << accumulate(vec.begin(), vec.end(), 0);
	cout << endl;
	vector<string> words = { "red", "slow", "quick", "turtle", "over" };
	elimDups(words);
	stable_sort(words.begin(), words.end(),
		[](const string & s1, const string & s2) {
			return s1.size() < s2.size();
		});
	for (const auto& s : words) cout << s << " ";
	cout << endl;
	auto i = partition(words.begin(), words.end(), hasFiveWords);
	words.erase(i, words.end());
	for (const auto& s : words) cout << s << " ";
	cout << endl;
	//lambda
	//auto add = [](int lhs, int rhs) {return lhs + rhs; };
	//lambda 的值捕获 和 引用捕获


}

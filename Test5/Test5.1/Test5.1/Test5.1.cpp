// Test5.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include<stdexcept>
//#include<new>
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	//test 5.14
	/*
	string pre_word, word, max_repeat_word;
	int repeat_times = 0, max_repeat_times = 0;
	while(cin >> word) {
		if (word == pre_word) {
			++repeat_times;
		}
		else {
			repeat_times = 1;
			pre_word = word;
		}

		if (max_repeat_times < repeat_times) {
			max_repeat_times = repeat_times;
			max_repeat_word = pre_word;
		}

	}
	if (max_repeat_times <= 1) {
		cout << "no word was repeated" << endl;
	} else {
		cout << "the word " << max_repeat_word << " occured " << max_repeat_times << endl;
	}
    std::cout << "Hello World!\n";

	//test 5.17
	vector<int> vec1{ 0,1,1,2 };
	vector<int> vec2{ 0,1,1,2,3,5,8 };

	auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
	for (decltype(vec1.size()) i = 0; i != size; ++i) {
		if (vec1[i] != vec2[i]) {
			cout << "false " << endl;
			return 0;
		}
	}
	cout << " ture " << endl;
	return 0;


	//test 5.19
	string rsp;
	do {
		cout << "input two strings ";
		string str1, str2;
		cin >> str1 >> str2;
		cout << (str1 <= str2 ? str1 : str2) << " is less more"
			<< "\n\n"
			<< "More? Enter yes or no";
		cin >> rsp;
	} while (rsp[0] == 'y' && !rsp.empty());
	return 0;

	//5.18
	string word, pre_word;

	while (cin >> word) {
		if (word == pre_word){
			break;
		}
		else {
			pre_word = word;
		}
	}
	if (cin.eof()) cout << "no word was repeated" << endl;
	else cout << pre_word <<" occured twice in suceesion" << endl;
		*/
	string curr, prev;
	bool twice_time = false;
	while (cin >> curr) {
		if (!isupper(curr[0])) {
			prev = "";
			continue;
		}
		if (prev == curr) {
			cout << curr << " occurs twice in succession." << endl;
			twice_time = true;
			break;
		}
		else {
			prev = curr;
		}
	}
	if (!twice_time) cout << "no word was repeated"<<endl;
}

// string operation
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
/*
//  定义方式
	string s1;
	string s2(s1);
	string s3("value");
//  string s3 = "value";
	string s4(10, 'c');
	cout << s4 << s3;
	int r;
	r = s3.size();
	cout << r << "\n";
//	两种输入string
	string word;
	while (cin >> word) {
		cout << word << endl;
	}

	while (getline(cin, word))
		if(!word.empty())
			if(word.size()>10)
				cout << word << endl;

	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size()) {
		if (s1.size() > s2.size())
			cout << s1 << "\n";
		else
			cout << s2 << "\n";
	}
	else
		cout << "s1 = s2" << endl;

// ex3_05b
	string word;
	string str;
	while (cin >> str){
		if (word.empty())
			word += str;
		else
			word += " " + str;
		cout << "the concatenated string is " << word << endl;
	}

//	计算标点符号
	string s("Hello,C++");
	decltype (s.size()) punct_cnt = 0;
	for (auto c : s) {
		if (ispunct(c))
			++punct_cnt;
	}
	cout << punct_cnt
		<< "punctuation characters in " << s << endl;

//  全部转换大写
	for (auto& c : s)
		if (islower(c))
			c = toupper(c);
	cout << s << endl;
//  部分转换大写
	if (!s.empty()) {
		cout << s[0] << endl;
	}
//  部分转换大写
	string str("something wrong");
	if (!str.empty())
		str[0] = toupper(str[0]);
	cout << str << endl;
//  部分转换大写
	for (decltype(s.size()) index = 0;
		index != s.size() && !isspace(s[index]);
		++index)
		str[index] = toupper(str[index]);
	cout << str << endl;
//  十六进制弱智版
/*	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< "sperated by spaces. Hit ENTER when finished: "
		<< endl;
	string result;
	string::size_type n;
	while (cin >> n)
		if (n < hexdigits.size())
			result += hexdigits[n];
	cout << "Your hex nubers is : " << result << endl	;

//  课后作业3.6

	string s1 = "new s1!@##";
	for (char& c : s1)
		c = 'X';

	cout << s1 << endl;
*/
// 课后作业3.10
	string s_in;
	cout << "Enter a string of characters including punctuation." << endl;
	while (getline(cin, s_in)) {
		for (auto i : s_in)
			if (!ispunct(i))
				cout << i;
	}
	return 0;

}



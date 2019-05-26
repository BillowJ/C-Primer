// project8.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream> //读写文件的类型；
#include<sstream>//读写内存string对象的类型；
#include<vector>
#include"test.h"
#include"ex7_26_sales_data.h"
using namespace std;

void fio();
istream& in(istream& is) {
	string buf;
	while (cin >> buf){
		cout << buf << endl;
	}
	is.clear();
	return is;
}


int main(int argc, char** argv)
{
	/*
//	in(std::cin);
	cout << "please enter a value ";
	cout << "hi! " << endl;
	cout << "hi! " << flush;
	cout << "hi! " << ends;
	cout << "-ends 添加空字符" << flush;
	cout << unitbuf << " hello!";
	*/
//关联流
/*	cin.tie(&cout);
	//old_item指向当前关联到的cin的流（如果有的话）
	ostream* old_tie = cin.tie(nullptr);
	cin.tie(&cerr);
	//cin重新关联cout
	cin.tie(old_tie);
*/
	//	fio();
/*	vector<string> vec;
	ReadFiletoVec("D:/Dir_C++/Test8/project8.1/book.txt", vec);
	for (const auto& str : vec) cout << str << " ";
	cout << endl;

	std::ifstream input(argv[1]); // use "../data/book.txt"
	//文本里的内容要符合格式！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	std::ofstream ouput(argv[2],ofstream::app);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
			
		}
		print(ouput, total) << std::endl;
	}
	else {
		std::cerr << "No data?! or wrong data!" << std::endl;

		


		}*/
	istringstream record;
	string line, word;//分别保存来自输入的一行和单词
	vector<PersonInfo> people;
	string filename;
	ifstream openfile(filename);
	if (!openfile) {
		cerr << "no data!" << endl;
		return -1;
	}
	while (getline(openfile, line)) {
		PersonInfo info;
//		istringstream record(line);
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);

	}
	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else {
				formatted << " " << nums;
			}
		}
		if (badNums.str().empty) {
			cout << entry.name << " " << formatted.str() << endl;
		}
		else {
			cerr << "input error" << entry.name <<"invaild number(s)"<< badNums.str() << endl;
		}
	}
/*
	string filename = "D:/Dir_C++/Test8/project8.1/book.txt";
	string lines;
	vector<string> vec;
	ifstream input(filename);
	if (!input) {
		cerr << "no data " << endl;
		return -1;
	}
	while (getline(input, lines)) vec.push_back(lines);

	for (auto& s : vec) {
		istringstream iss(s);
		string word;
		while (iss >> word) cout << word << endl;
	}
	*/
	return 0;
}

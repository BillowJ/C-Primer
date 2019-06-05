// Project12.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;
int main()
{
	//ex12.23
	const char* c1 = "hello ";
	const char* c2 = "world";
	auto len = strlen(c1) + strlen(c2) + 1;
	char* r = new char[len]();//默认初始化 动态数组 char[]
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	cout << r << endl;

	string str1 = { "hello " };
	string str2 = { "world" };
	strcpy_s(r, len, (str1 + str2).c_str());
	cout << r << endl;
	//ex12.24
	size_t want_size = 10;
	char* r1 = new char[want_size + 1];//char 数组长度要加上末尾的空格
	char input;
	size_t i = 0;
	while (cin >> input)
	{
		r1[i++] = input;
	}
	cout << r1 << endl;
//	delete[] r1;

	int n = 10;
	allocator<string> alloc;//可以分配string的allcator对象
	auto const p = alloc.allocate(n); //分配n个初始化的string

}




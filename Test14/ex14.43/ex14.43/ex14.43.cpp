// ex14.43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;
int main()
{
	auto data = { 2, 4, 5, 20 };
	int input;
	cin >> input;
	std::modulus<int> mod;
	auto prediator = [&](int i) { return 0 == mod(input, i); }; //lambda通过&捕获所有变量
	auto res = std::all_of(data.begin(), data.end(), prediator); //all_of, any_of, none_of 位于<algorithm> 头文件中
	std::cout << (res ? "yes" : "no") << endl;
}

// Project1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>
#include <string>
#include <map>

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };
struct divide {
	int operator() (int i, int j) {
		return i / j;
	}
};
int main()
{
	std::map<std::string, std::function<int(int, int)>> binops;
	std::function<int(int, int)> f1(add);
	std::function<int(int, int)> f2(divide());
	std::function<int(int, int)> f3 = [](int i, int j) { return i % j; };
	binops.insert({ "+", add });
	binops.insert({ "*", [](int i, int j) { return i * j; } });
	binops.insert({ "%", mod });//命名后的lambda表达式
	binops.insert({ "/", divide() });
	binops.insert({ "-", std::minus<int>() });

	binops["+"](10, 5); //调用add(10, 5)
	binops["/"](10, 5);
	//...以此类推
}

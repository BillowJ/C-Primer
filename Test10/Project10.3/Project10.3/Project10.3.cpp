// Project10.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include<list>
using namespace std;
bool isShort(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}
void elimDups(list<string>& lis) {
	lis.sort(isShort);
	lis.unique();
}

int main() {
	list<string> lis = { "aa", "aa", "aa", "aa", "aasss", "aa" };
	elimDups(lis);
	for (const auto& e : lis) std::cout << e << " ";
	std::cout << std::endl;
}

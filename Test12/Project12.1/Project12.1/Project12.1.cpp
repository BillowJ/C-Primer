// Project12.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"head.h"
using namespace std;
int main()
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	if (p1 && p1->empty())* p1 = "hi";
}


// Project7.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
class NoDefault {
public:
	NoDefault(const int){}
};
struct C
{
	C() : default_c(0){} //默认给default_c赋值为0
private:
	NoDefault default_c;
};

int main()
{
	C c;
	std::vector<C> vec(10);
	return 0;
}



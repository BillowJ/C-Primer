// ex14.42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//涉及之前的lambda表达式的知识
//1.bind函数 2.placeholder的使用   --P355

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

int main()
{
	using std::placeholders::_1;
	std::vector<int> vec{ 1,11,111,1111 };
	auto count = std::count_if(vec.cbegin(), vec.cend(), 
							   std::bind(std::greater<int>(), _1, 1024));
	
	std::vector<std::string> svec{ "pooh", "pooh", "BillowJ", "pooh" };
	auto res_str = 
		std::find_if(svec.cbegin(), svec.cend(),
					 std::bind(std::not_equal_to<std::string>(), _1, "pooh")); //res_str是函数返回的指针
	std::cout << *res_str << std::endl;

	std::transform(vec.begin(), vec.end(),vec.begin(),
		std::bind(std::multiplies<int>(), _1, 2)); //transform 在 algorihm头文件里

	for (auto i : vec) std::cout << i << " " << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单


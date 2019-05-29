// Project11.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"head.h"
using namespace std;

int main()
{
	ifstream ifs_map("D:/Dir_C++/Test11/Project11.3/word_transformation_bad.txt"),
		ifs_content("D:/Dir_C++/Test11/Project11.3/given_to_transform.txt");
	if (ifs_map && ifs_content)
		word_transform(ifs_map, ifs_content);
	else
		std::cerr << "can't find the documents." << std::endl;
}

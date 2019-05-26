// Project7.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"ex7_04.h"
#include"ex7_11_sales_data.h"
int main()
{
	cout << "1. default way: " << endl;
	cout << "----------------" << endl;
	Sales_data s1;

	cout << "\n2. use std::string as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s2("CPP-Primer-5th");

	cout << "\n3. complete parameters: " << endl;
	cout << "----------------" << endl;
	Sales_data s3("CPP-Primer-5th", 3, 25.8);

	cout << "\n4. use istream as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s4(std::cin);
	print(std::cout, s4) << std::endl;

	string s = "IPX";
	Sales_data i("IPX", 3, 15);
	i.combine(s);
	print(cout, i);

	return 0;
}
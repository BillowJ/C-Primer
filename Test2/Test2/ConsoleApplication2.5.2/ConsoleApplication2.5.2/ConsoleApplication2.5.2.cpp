#include <iostream>
#include<string>
#include"ex2_42_sales_data.h"
using namespace std;
int main()
{
	/*int i = 0,&r = i;
	const int ci = i, &cr = ci;
	auto a = r;
	auto b = ci;
	auto c = cr;//(const) int, auto 忽略顶层const
	auto d = &i; //指向int类型的指针
	auto f = &ci;//指向const int 的指针
	std::cout << c;
*/
	Sales_data book1, book2;
	double price1, price2;
	std::cin >> book1.bookNO >> book1.Book_Sales >> price1;
	std::cin >> book2.bookNO >> book2.Book_Sales >> price2;
	book1.revenue = book1.Book_Sales * book1.Book_Sales;
	book2.revenue = book2.Book_Sales * book2.Book_Sales;
	if (book1.bookNO == book2.bookNO) {
		unsigned totalCnt = book1.Book_Sales + book2.Book_Sales;
		double totalRevenue = book1.revenue + book2.revenue;
		std::cout << book1.bookNO << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			std::cout << totalRevenue / totalCnt << " " << std::endl;
		else
			std::cout << "(no sales!)" << std::endl;
	}
	else
	{
		std::cerr<<"Data must refer to same id!" << std::endl;
		return -1;
	}
}
	



	/*const int i = 42;
	auto j = i; const auto& k = i; auto *p = &i;
	const auto j2 = i, & k2 = i;
	std::cout << j <<"\t"<< k << "\t" << *p<<"\t" << j2<<"\t" << k2;
}
*/

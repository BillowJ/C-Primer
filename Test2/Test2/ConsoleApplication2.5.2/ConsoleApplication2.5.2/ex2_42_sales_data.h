#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<string>
struct Sales_data {
	std::string bookNO;
	std::string bookName; 
	unsigned int Book_Price = 0;
	unsigned int Book_Sales = 0;
	double revenue = 0;
};
#endif

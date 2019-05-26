#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<string>
struct Sales_data {
	std::string bookNO;
	unsigned int Book_Sales = 0;	
	double Book_Price = 0;
	double revenue = 0;
	
	void CalcRevenue(double price);
	void SetData(Sales_data data);
	
	 
};

void Sales_data::CalcRevenue(double price)
{
	revenue = Book_Sales * price;
}


void Sales_data::SetData(Sales_data data)
{
	bookNO = data.bookNO; 
	Book_Sales = data.Book_Sales;
	revenue = data.revenue;
}
#endif

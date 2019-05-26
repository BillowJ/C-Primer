#pragma once
#ifndef CP5_ex7_11_h
#define CP5_ex7_11_h

#include <iostream>
#include <string>

struct Sales_data;
std::istream& read(std::istream&, Sales_data&);

// Add constructors to your Sales_data class
struct Sales_data {
	friend std::istream& read(std::istream&, Sales_data&);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
public:
	Sales_data() : Sales_data("", 0, 0) { std::cout << "Sales_data()" << std::endl; }
	Sales_data(const std::string& s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(n* p) {
		std::cout << "Sales_data(const std::string& s, unsigned n, double p)" << std::endl;
	}
	Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}
	Sales_data(std::istream& is); 

	
	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);	
	

private:
	double avg_price() const { return units_sold ? revenue / units_sold : 0; }
	unsigned units_sold = 0;
	double revenue = 0.0;
	std::string bookNo;
};



#endif
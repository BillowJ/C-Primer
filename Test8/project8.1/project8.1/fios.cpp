#include<fstream>
#include <iostream>
#include<vector>
#include<string>
#include"test.h"
using namespace std;

void fio() {
	string ifile = "Image.png";
	fstream fstream;
	ifstream in(ifile);
	ofstream out;
	out.open(ifile + ".copy");
	if (out) cout << "succusee" << endl;
}

int ReadFiletoVec(const string& fileName, vector<string>& vec) {
	ifstream ifs(fileName);
	//判断是否成功打开
	if (ifs) {
		string buf;
		//while (ifs >> buf)
		while (std::getline(ifs, buf)) {
			vec.push_back(buf);
		} 
	}
	else {
		cerr << "error!" << endl;
		return -1;
	}
}

istream& func(istream& is) {
	std::string buf;
	while (is >> buf) std::cout << buf << std::endl;
	is.clear();
	return is;
}

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

/*
Sales_data 中 read print 源码参考
std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

#include <fstream>
#include <iostream>

#include "../ch07/ex7_26_sales_data.h"

int main(int argc, char** argv)
{
	std::ifstream input(argv[1]); // use "../data/book.txt"

	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
	}
}

*/
#pragma once
#include <iostream>
#include<memory>
#include<vector>
#include<list>
#include<initializer_list>
#include<new>//nothrow
using namespace std;
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<string> il);
	size_type size() { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const string& t) { data->push_back(t); }
	void pop_back();
	string& front();
	const string& front() const;
	string& back();
	const string& back() const;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const;
};
//构造函数的定义
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }//make_shared() 默认值初始化

StrBlob::StrBlob(initializer_list<string> il) ://initializer_list<string> 初始化一个不能更改的常量值容器类型
	data(make_shared<vector<string>>(il)) { }//make_shared() 使用il的值进行初始化

//异常处理程序
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);//抛出异常~
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob.");
	return data->front();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob.");
	return data->front();
}
string& StrBlob::back() {
	check(0, "back on empty StrBlob.");
	return data->back();
}

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob.");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob.");
	data->pop_back();
}

void process(std::shared_ptr<int> ptr)
{
	std::cout << "inside the process function:" << ptr.use_count() << "\n";
}
// ex13_53_HasPtr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ex13_54_HasPtr.h"
using namespace std;
HasPtr::HasPtr(const std::string& s) : ps(new std::string(s)), i(0)
{
	std::cout << "call constructor" << std::endl;
}

HasPtr::HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i)
{
	std::cout << "call copy constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i)
{
	p.ps = 0;
	std::cout << "call move constructor" << std::endl;
}

HasPtr::~HasPtr()
{
	std::cout << "call destructor" << std::endl;
	delete ps;
}

//拷贝赋值运算符
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	std::cout << " call copy assignment" << std::endl;
	return *this;
}



//移动赋值运算符
HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept {
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
		cout << "call move assignment" << endl;
	}
	return *this;
}

/*
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}
*/
//定义交换操作
inline
void swap(HasPtr& lhp, HasPtr& rhp) {
	using std::swap;
	swap(lhp.ps, rhp.ps);
	swap(lhp.i, rhp.i);
	std::cout << "call swap" << std::endl;
}

int main(){
	HasPtr h1("hello"), h2("world"), * h3 = new HasPtr("World");
	h1 = h2;
	h1 = std::move(*h3);
}

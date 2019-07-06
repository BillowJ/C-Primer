#include <iostream>
#include "ex13_49_Message.h"
using namespace std;

/*
class HasPtr {
public:
	HasPtr(const string& s = std::string()) : ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr& p) : ps(new string(*p.ps)), i(p.i) { }
	//HasPtr& operator = (const HasPtr&);
	//添加移动构造函数
	HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
	//添加赋值运算符 即使移动运算也是拷贝运算
	HasPtr& operator = (HasPtr rhs) {
		swap(*this, rhs);
		return *this;
	}
	~HasPtr() { delete ps; }
private:
	std::string* ps;
	int i;
};


int main()
{
	HasPtr hp, hp1, hp2;
	hp = hp2;//拷贝运算
	hp1 = std::move(hp);//移动运算，不分配任何内存

}
*/

int main()
{
	Message firstMail("hello");
	Message signInMail("welcome to cppprimer");
	Folder mailBox;

	firstMail.save(mailBox);
	signInMail.save(mailBox);
	mailBox.print_debug();

	firstMail = std::move(signInMail);
	mailBox.print_debug();
}
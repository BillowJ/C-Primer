// Project13.1.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;

//13.18
struct Employee {
	static int s_increment;//设置static变量 每次生成一个唯一 id_

	Employee(const string& name): name_(name) { 
		id_ = s_increment++;
	}

	Employee() {
		id_ = s_increment++;
	}
	//不需要拷贝构造函数和拷贝赋值操作符，则delete操作
	Employee(const Employee& e) = delete;
	Employee& operator = (const Employee&) = delete;

	const int id() {
		return id_;
	}

private:
	int id_;
	string name_;
};

int Employee::s_increment = 0;


int main()
{
    std::cout << "Hello World!\n";
}

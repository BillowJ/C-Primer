#pragma once
#ifndef CP5_ex7_04_h
#define CP5_ex7_04_h

#include <string>
using namespace std;

struct Person {
	//非成员函数的所作的友元声明
	friend std::istream& read(std::istream& is, Person& person);
	friend std::ostream& print(std::ostream& os, const Person& person);
public:
	Person() = default;
	Person(const string& s1, const string& s2) : name(s1), address(s2) {};
	Person(const string& s1) : name(s1) {};
	explicit Person(std::istream& is) { read(is, *this); }
private:
	std::string name;
	std::string address;
public:
	const std::string& getName() { return name; }
	const std::string& getAddress() { return address; }
};
//Person接口的非成员函数组成部分的声明
std::istream& read(std::istream& is, Person& person) {
	is >> person.name >> person.address;
	if (!is) person = Person(); //默认值
	return is;
}

std::ostream& print(std::ostream& os,const Person& person) {
	os << person.name << person.address;
	return os;
}

#endif
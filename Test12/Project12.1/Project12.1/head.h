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
//���캯���Ķ���
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }//make_shared() Ĭ��ֵ��ʼ��

StrBlob::StrBlob(initializer_list<string> il) ://initializer_list<string> ��ʼ��һ�����ܸ��ĵĳ���ֵ��������
	data(make_shared<vector<string>>(il)) { }//make_shared() ʹ��il��ֵ���г�ʼ��

//�쳣�������
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);//�׳��쳣~
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
// Test6.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<string>

using namespace std;
//函数类型
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2;

//FuncP 和 FuncP2 是函数指针
typedef bool (*FuncP) (const string&, const string&);
typedef decltype(lengthCompare)* FunP2;

using F = int(int*, int);//函数类型
using PF = int(*) (int*, int);//指针类型
//等价声明 
PF f1(int);
F* f1(int);
int (*f1(int)) (int*, int);
auto f1(int) -> int (*) (int*, int);

bool lengthCompare(const string&, const string&) {
	return 0;
}

string::size_type sumLength(const string&, const string&);

bool cstringCompare(const char&, const char&);
//函数指针做形参
void useBigger(const string&, const string&,
	bool pf(const string&, const string&));
//等价声明(*)and ()
void useBigger(const string&, const string&,
	bool (*pf)(const string&, const string&));
//等价声明 （typedef 版本）
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP);

//test6.54 
int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;

int test(int, int);
typedef int (*f) (int, int);
vector<f> vec11;

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }


int main()
{
	//函数指针pf 指向一个函数 其参数为两个const string 引用
	bool (*pf)(const string &, const string &);
	pf = lengthCompare;
	pf = &lengthCompare; //取地址
	//使用函数指针
	bool b1 = pf("hello", "goodbye");
	bool b2 = (*pf)("hello", "goodbye");
    std::cout << "Hello World!\n";
	//在函数指针调用时不存在类型转化
	//pf = cstringCompare;
	//不指向任何函数
	pf = 0; pf = nullptr;
//---------------------------------------------------------
	string s1 = "hello", s2 = "world";                   //
	//函数指针做实参                                     //
	useBigger(s1, s2, lengthCompare);                    //
//---------------------------------------------------------
	
//Func 和 Fun2 是函数类型
/*bool lengthCompare(const string&, const string&) {
	return 0;
}*/
	std::vector<decltype(func)*> vec{ add, subtract, multiply, divide };
	for (auto f : vec)
		std::cout << f(2, 2) << std::endl;
}
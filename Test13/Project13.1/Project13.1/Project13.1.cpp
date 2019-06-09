// Project13.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<functional>
using namespace std;

class HasPtr {
public:
	//赋值运算符
	HasPtr(const string& s = string()) : ps(new string (s)), i(0) {}
	//拷贝构造函数
	HasPtr(const HasPtr& hap) : ps(new string(*hap.ps)), i(hap.i) { }

	HasPtr& operator = (const HasPtr& hap) {
		i = hap.i;
		string* new_ps = new string(*hap.ps);
		delete ps;
		ps = new_ps;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	string* ps;
	int i;
};

struct X {
	X() { cout << " X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X(X&) { cout << "X( X&)" << endl; }
	
	X& operator = (const X&) {
		cout << "X& operator=(const X&)" << endl;
		return *this;
	}

	~X()
	{
		cout << "~X()" << endl;
	}
};
//N皇后问题
int totalNQueen(int n) {
	int upperlim = (1 << n) - 1, sum = 0;
	std::function<void(int, int, int)> dfs = [&](int row, int l, int r) {
		if (row == upperlim) { ++sum; return; }
		for (int cur = upperlim & (~(row | l | r)), pos = 0; cur; dfs(row + pos, (l + pos) << 1, (r + pos) >> 1)) {
			pos = cur & (-cur);
			cur -= pos;
		}
	};
	dfs(0, 0, 0);
	return sum;
}


void f(const X& rx, X x)
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
}
class numbered {
public:
	numbered() {
		static int unique = 10;
		symn = unique++;
	}

	
	int symn;

};
void f1(const numbered& s) {
	cout << s.symn << endl;
}
int main()
{
	/*
	X* px = new X;
	f(*px, *px);
	delete px;
	X x, x1;
	x = x1;*/
	numbered a, b = a, c = b;
	f1(a);
	f1(b);
	f1(c);
	
}


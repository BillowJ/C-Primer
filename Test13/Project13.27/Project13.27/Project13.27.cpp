// Project13.27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//使类具有指针的特性
class HasPtr {
//public:friend void swap(HasPtr& lhp, HasPtr& rhp);
//	   friend bool operator < (const HasPtr& lhs, const HasPtr& rhs);
public:
	HasPtr(const string& s = string() ) : ps(new string(s)), i(0), use(new string::size_type(1)) { }
	HasPtr(const HasPtr& hap) : ps(hap.ps), i(hap.i), use(hap.use) { ++* use; }
	HasPtr& operator = (const HasPtr&);
	~HasPtr();
private:
	string* ps;
	string::size_type* use;//自定义计数器
	int i;
};

HasPtr::~HasPtr() {
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
}
//拷贝其指针 指向相同的string
HasPtr& HasPtr::operator=(const HasPtr& hap) {
	++* hap.use;
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	use = hap.use;
	ps = hap.ps;
	i = hap.i;
	return *this;
}
/*用于类值
//定义交换操作
inline
void swap(HasPtr& lhp, HasPtr& rhp) {
	using std::swap; 
	swap(lhp.ps, rhp.ps);
	swap(lhp.i, rhp.i);
}

bool operator < (const HasPtr& lhs, const HasPtr& rhs) {
	return *lhs.ps < *rhs.ps;
}*/
int main()
{
    std::cout << "Hello World!\n";
}


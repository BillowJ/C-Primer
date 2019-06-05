// Project12.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"head.h"
using namespace std;
int main()
{
/*
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	if (p1 && p1->empty())* p1 = "hi";
*/
	//定位new 若无法分配内存 不抛出错误 而是返回空指针
	int* p1 = new (nothrow) int;
	delete p1;//p1必须指向一个动态分配的对象or空指针

	//share_ptr 和 new 的结合使用
	shared_ptr<int> p2(new int(1024));
	
	//12.10
	std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p));

    /**
      * codes below shows how the reference count change.
      */
    /*std::cout << p.use_count() << "\n";
    auto q = p;
    std::cout << p.use_count() << "\n";
    std::cout << "the int p now points to is:" << *p << "\n";
    return 0;
	*/
	auto x = new int();
	
	process(shared_ptr<int>(x));
}


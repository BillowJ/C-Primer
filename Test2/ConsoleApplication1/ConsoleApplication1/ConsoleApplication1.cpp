
#include <iostream>
#include<cstdlib>
int main()
{
	//三种空指针定义：
	int* p1 = NULL;
	int* p2 = nullptr;
	int* p3 = 0;
	int a = 0, b = 3;
	std::cout << a<<"\n";
	p1 = &a;
	if (*p1) {
		std::cout << "fei kong\n";
	}
	else
	{
		std::cout << "kong \n";
	}
	*p1 = 6;
	std::cout << a<<"\n";
	p1 = &b;
	std::cout << *p1<<"\n";
	double c = 1.00;
	double* p = &c;
	std::cout << c<<'\n';
	void* n = &c;
	if (n = p) {
		std::cout << "Pass!";
	}

}


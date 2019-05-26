
#include <iostream>

int main()
{
	unsigned int u = 10, u2=42;
	int i = 10, i2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	std::cout << "\a \???\b制表符?\b\??  \a" << std::endl;
	std::cout << "\v \f进纸符 \f \v" << std::endl;
	std::cout << "\"\'引号 \' \" " << std::endl;

}

/*
Answer:
C++ guarantees short and int is at least 16 bits, long at least 32 bits, long long at least 64 bits.
The signed can represent positive numbers, negative numbersand zero, while unsigned can only represent numbers no less than zero.
The Cand C++ standards do not specify the representation of float, doubleand long double.It is possible that all three implemented as IEEE double - precision.



use double, or also float.
-------------------- -
作者：MISAYAONE
来源：CSDN
原文：https ://blog.csdn.net/misayaaaaa/article/details/53200773 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
#include<vector>
#include <iostream>
using namespace std;
//6.21
void test(int a, int* p) {
	if (a > * p) cout << a << endl;
	else cout << *p << endl;
	//return (a > *p) ? a : *p;
}

//6.22
void change(const int*& p1, const int*& p2) {
	auto p3 = p1;
	p1 = p2;
	p2 = p3;
}
/*int main()
{
	const int i = 1, j = 2;
	const int* p1 = &i;
	const int* p2 = &j;
	change(p1,p2);
	cout << *p1 << endl;
	cout << *p2 << endl;
*/
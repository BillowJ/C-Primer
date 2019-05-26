#include<string>
#include <iostream>
using namespace std;
int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	//a range for to manage the iteration
	for (int(&p)[4] : ia)
		for (int q : p) cout << q << " ";
	std::cout << endl;

	//ordinary for loop using subscrpts
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j != 4; ++j) cout << ia[i][j] << " ";
	cout << endl;

	//using pointer
	for (int(*p)[4] = ia; p != ia + 3; ++p)
		for (int* q = *p; q != *p + 4; ++q) cout << *q << " ";
	cout << endl;
	//use type alias
	using arry_int = int[4];
	for (arry_int& p : ia)
		for (int q : p) cout << q << " ";
	cout << endl;

	for (arry_int* p = ia; p != ia + 3; ++p)
		for (int* q = *p; q != *p + 4; ++q) cout << *q << " ";
	cout << endl;
	
	// use auto 
	for (auto& p : ia)
		for (int q : p) cout << q << " ";
	cout << endl;

	for (auto* p = ia; p != end(ia); p++)
		for (auto* q = *p; q != end(*p); ++q) cout << *q << " ";
	cout << endl;
}

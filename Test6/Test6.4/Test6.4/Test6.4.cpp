#include <iostream>
#include<vector>
using namespace std;
bool str_subrange(const string& str1, const string& str2) {
	if (str1.size() == str2.size()) return str1 == str2;

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i]) return -1;
	}
	return 0;
}

//6.34
//递归调用 输出vector对象
void print(vector<int>::iterator beg, vector<int>::iterator end) {
	if (beg != end) {
		cout << *beg << " ";
		print(next(beg), end);
	}
}

int main()
{
	vector<int> vec{ 1,2,3,4,5,6 };
	print(vec.begin(), vec.end());
    std::cout << "Hello World!\n"; 
}
/*
using arrT = string[10];
string arr{"1","2"};
arrT& func(arrT& arr);
auto func1(arrT& arr)->string(&)[10];

string arr[10];
decltype(arr)& func1(arrT& arr);
*/

int odd[] = { 1,2,3,4,5, 6 };
int even[] = { 0,2,4,5,6,7 };

decltype(odd)& arrPtr(int i) {
	return (i % 2) ? odd : even;
}
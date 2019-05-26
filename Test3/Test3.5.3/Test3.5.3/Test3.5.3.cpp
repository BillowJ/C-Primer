// Test3.5.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<iterator>
using namespace std;

bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2) {
	if ((pe1 - pb1) != (pb1 - pb2)) {
		return false;
	}
	else {
		for (int* i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
			if (*i != *j) return false;
	}
}
int main()
{
	int arr1[] = { 0,1,2 };
	int arr2[] = { 0,2,4 };

	if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	cout << "-------------------" << endl;
	
	vector<int> vec1 = { 1,1,1 };
	vector<int> vec2(3, 1);
	if (vec1 == vec2) cout << "equal" << endl;
	else cout << "not equal" << endl;

	return 0;
}


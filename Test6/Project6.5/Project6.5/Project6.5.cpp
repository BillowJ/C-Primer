#include "pch.h"
//#define NDEBUG
#include <iostream>
using namespace std;

inline bool
isshorter(const string& s1, const string& s2) {
	assert(s1.size() != 0);
	return s1.size() < s2.size();
}

int main()
{
	vector<int> ch{ 1,2,3,4,45,12,5,34,45 };
	int ia[] = { 1,2,3,4,45,12,5,34 };
	size_t size = std::size(ia);
//	print(ia, size);
//	print(ch.begin(), ch.end());
//	printVec(ch);
//	test648();
	cout << FIND_MAX_CROSSING_SUBARR(ia, 1, 5, 8) << endl;
}

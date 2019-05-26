// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

void print(const int ia[], size_t size) {
	assert(size < 5);
#ifdef NDEBUG
	cerr << __func__ << ": array size is " << size << endl;
#endif // NDEBUG

}

void print(vector<int>::iterator beg, vector<int>::iterator end) {
	if (beg != end) {
		std::cout << *beg << " ";
		print(std::next(beg), end);
	}
}

void printVec(vector<int>& vec){
#ifndef NDEBUG
	cout << "vec size : " << vec.size() << endl;
#endif // !NDEBUG
	if (!empty(vec)) {
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << " ";
	}

}

void test648() {
	string s;
	while (cin >> s && s != "sought") {

	}
	assert(!cin || s == "sought");
}

int FIND_MAX_CROSSING_SUBARR(int arr[], int low, int mid,  int high) {
	int left_sum = INT_MIN, max_left = 0;
	int sum_l = 0;
	for (int i = mid; i != low; --i) {
		sum_l += arr[i];
		if (sum_l > left_sum) {
			left_sum = sum_l;
			max_left = i;
		}
	}
	int right_sum = INT_MIN, max_right = 0;
	int sum_r = 0;
	for (int j = (mid + 1); j != high; ++j) {
		sum_r += arr[j];
		if (sum_r > right_sum) {
			right_sum = sum_r;
			max_right = j;
		}
	}

	return (max_left);
}
// 当使用预编译的头时，需要使用此源文件，编译才能成功。

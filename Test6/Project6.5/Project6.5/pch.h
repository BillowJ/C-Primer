// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H
#include<cassert>
#include<vector>
#include<iostream>
#include<limits>
using namespace std;
void print(const int ia[], size_t size);
void print(vector<int>::iterator beg, vector<int>::iterator end);
void printVec(vector<int>& vec);
void test648();
int FIND_MAX_CROSSING_SUBARR(int arr[], int low, int mid, int high);
// 添加要在此处预编译的标头

#endif //PCH_H

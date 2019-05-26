// Project9.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<list>
#include<forward_list>
using namespace std;

void insertest(forward_list<string> fls, string str1, string str2) {
	auto prev = fls.before_begin();
	auto size = distance(fls.begin(), fls.end());
	for (auto curr = fls.begin(); curr != fls.end(); ++curr) {
		if (*curr == str1) curr = fls.insert_after(curr,str2);
	}
	//通过判断for循环前后得到的容器长度来判断是否存在str1
	if (size == std::distance(fls.begin(), fls.end())) fls.insert_after(prev, str2);
}

int main()
{
	forward_list<int> flist{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	list<int> lis(ia, end(ia));
	vector<int> vec(lis.begin(), lis.end());
	//! remove odd value
	for (auto prev = flist.before_begin(), curr = flist.begin(); curr != flist.end();) {
		if (*curr % 2) {
			curr = flist.erase_after(prev);
		}
		else {
			prev = curr++;
		}
	}

	for (auto i : flist) cout << i << " ";
	cout << endl;
	
	//! remove odd value
	for (auto it = lis.begin(); it != lis.end();)
		if (*it & 0x1)
			it = lis.erase(it);
		else
			++it;

	//! remove even value
	for (auto it = vec.begin(); it != vec.end();)
		if (!(*it & 0x1))
			it = vec.erase(it);
		else
			++it;

	//! print
	cout << "list : ";
	for (auto i : lis) cout << i << " ";
	cout << "\nvector : ";
	for (auto i : vec) cout << i << " ";
	cout << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

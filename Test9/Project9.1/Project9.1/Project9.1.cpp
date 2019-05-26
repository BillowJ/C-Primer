// Project9.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

vector<int>::const_iterator isNumberExist(vector<int>::iterator beg, vector<int>::iterator end, int tag);
int main()
{
	vector<int> vec{ 1, 2, 4, 5, 6 };
	vector<int> vec1;
	vector<int> vec2(10);
	vector<int> vec3(10, 1);
	vector<int> vec4{};
	vector<int> ve5(vec3);
	vector<int> vec6(vec.begin() + 1, vec.end());
	list<int> lis;
	vector<double> vecdou(lis.begin(), lis.end());
	vector<double> vecdou1(vec1.begin(), vec1.end());
	list<const char*> li{"BillowJ", "Jing", "MaxWell"};
	vector<string> vec8;
	std::cout << std::boolalpha << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << (vector<int>(lis.begin(), lis.end()) == vec1) << endl;
	vec8.assign(li.begin(), li.end());
	for (const auto& i : vec8) {
		cout << i << " ";
	}
	cout << endl;

	list<int> list{ 1,3,45,34,23,12,45,56,34,23,12 };
	deque<int> odd, even;
	for (auto iter = list.begin(); iter != list.end(); ++iter) {
		(*iter & 0x1 ? odd : even).push_back(*iter);
	}

	auto val = vec.back();
	auto& val1 = vec.front();
	cout << vec.front() << " ";
	cout << *vec.begin() << endl;
	cout << endl;


/*	list<string> list;
	for (string words;  cin >> words; list.push_back(words));
	for (auto iter = list.cbegin(); iter != list.end(); ++iter) {
		cout << *iter << ends;
	}

/*	deque<string> deq;
	while (std::cin >> words) {
		deq.push_back(words);
	}
	for (auto& w : deq) {
		cout << w << " ";
	}
	cout << endl;
	*/
/*	用于测试上述容器的构造函数
	for (const auto i : vecdou1) {
		cout << i << " ";
	}
	*/
//	int flag = 5;
//	isNumberExist(vec.begin(), vec.end(), flag);
}

vector<int>::const_iterator isNumberExist(vector<int>::iterator beg, vector<int>::iterator end, int tag) {
	for (; beg != end; ++beg) {
		if (*beg == tag) {
			return beg;
		}
		else {
			return end;
		}
	}
	
}

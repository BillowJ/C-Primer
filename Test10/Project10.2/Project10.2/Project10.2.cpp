// Project10.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <algorithm>
#include <functional>
#include<numeric>
#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include<iterator>
#include<list>
using namespace std;

bool lessThanOrEqualTo(const string& s, string::size_type sz) {
	return s.size() <= sz;
}

bool checksize(const string& s, string::size_type sz) {
	return s.size() < sz;
}
/*template <typename Sequence> void print(Sequence const& seq)
{
	for (const auto& i : seq) std::cout << i << " ";
	std::cout << std::endl;
}*/

int main()
{
	std::vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling",
								"evan617" };
	std::cout << count_if(authors.begin(), authors.end(), bind(lessThanOrEqualTo, placeholders::_1, 6)) << endl;
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	string s = "BillowJ";
	std::cout << *find_if(vec.begin(), vec.end(), bind(checksize,s,placeholders::_1));
//  10.28
/*	vector<int> num = { 1,2,3,4,5,6,7,8,9 };
	list<int> in, back, front;
	copy(num.begin(), num.end(), inserter(in, in.begin()));
	print(in);

	copy(num.begin(), num.end(), back_inserter(back));
	print(back);

	copy(num.begin(), num.end(), front_inserter(front));
	print(front);
	//流迭代器
	istream_iterator<int> inn(cin);
	//指向尾hou
	istream_iterator<int> eof;
	cout << accumulate(inn, eof, 0) << endl;*/
//	list<int> vec2(inn, eof); 
//	print(vec2);
/*	char ca1[] = {' ','\0'};//c风格字符串以空字符null 结束  “” 自动添加空字符串
	ostream_iterator<int> out_iter(cout, ca1);//out_iter(cout, " "); 自动添加空字符串
	for (auto e : vec) {
		*out_iter++ = e;
	}
	cout << endl;
	*/

	ifstream ifs("D:/Dir_C++/Test10/Project10.2/test.txt");
	istream_iterator<string> fin(ifs), eof;
	ostream_iterator<string> out(cout, " ");
	vector<string> vectxt;
	copy(fin, eof, back_inserter(vectxt));

	copy(vectxt.begin(), vectxt.end(), out);
	//10.33
	/*
	int main(int argc, char** argv)
{
    if (argc != 4) return -1;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
//********************************
    std::for_each(in, in_eof, [&out_odd, &out_even](const int i) {
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });
//********************************
    return 0;
}*/

}


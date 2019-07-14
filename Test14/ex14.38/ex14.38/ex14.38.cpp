

#include <iostream>
#include<fstream>
using namespace std;
class Count_times
{
public:

	Count_times(size_t lower, size_t upper) : max(upper), min(lower) { }
	bool operator()(const string&);
private:
	size_t max;
	size_t min;
};

bool Count_times::operator()(const string& s) {

	return s.length <= max && s.length >= min;

}


int main()
{
	std::ifstream fin("../");
	size_t quantity7 = 0, quantity8 = 0;
	Count_times test7(1, 7), test8(1,8);
	for (string word; fin >> word;) {
		if (test7(word)) ++quantity7;
		if (test8(word)) ++quantity8;
	}

	cout << "长度1-7的单词出现次数:" << quantity7 << "\n"
		<< "长度1-8的单词出现次数:" << quantity8 << endl;
} 


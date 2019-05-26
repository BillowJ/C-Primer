#include<iostream>
using namespace std;
void rad(initializer_list<int>);
int main(int argc, char** argv) {
	string str;
	for (int i = 1; i != argc; ++i) {
		str += argv[i];
		str += " ";
	}
	cout << str << endl;
	rad({1,2,3,4,5,6,7});
}
//6.27
void rad(initializer_list<int> i) {
	for (auto beg = i.begin(); beg != i.end(); ++beg)
		cout << *beg << " ";
	cout << endl;

}
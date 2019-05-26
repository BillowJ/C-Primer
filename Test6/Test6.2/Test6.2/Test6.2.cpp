#include <iostream>
#include<vector>
using namespace std;
void change(int &p1, int &p2) {
	auto r = p1;
	p1 = p2;
	p2 = r;
}

bool hasupper(const string& s) {
	for(auto c : s)
		if (isupper(c)) return true;
	return false;
}

string makelower(string& s) {
	for (auto& i : s)
		if (isupper(i)) i = tolower(i);
	return s;
}

//bool compare(const matrix& p1, const matrix& p2);
//vector<int>::iterator change_val(int ,vector<int>::iterator)

int main()
{
	int a = 1, b = 2;
	change(a, b);
	cout << "a: " << a << "\n";
	cout << "b : " << b << endl;
	/*
	for(int a, b;cout <<"please enter: \n",cin >> a >> b;){
		change(&a, &b);
		cout << a <<" " << b << endl;
	*/
	//修改后的 引用类型的参数调用	
	/*
	for(int a, b;cout <<"please enter: \n",cin >> a >> b;){
		change(a, b);
		cout << a <<" " << b << endl;
	*/
	string str("hello,world!");
	cout << boolalpha << hasupper(str) << endl;
	cout << makelower(str) << endl;
}


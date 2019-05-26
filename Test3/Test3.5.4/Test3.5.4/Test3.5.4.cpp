#include <iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
/*	const char cal[] = "a string example";
	const char ca2[] = "a diff example";
	if (strcmp(cal, ca2) < 0) cout << "1" << endl;
	else cout << "0" << endl;

	const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
	const char s[] = "111";
	const char* cp = ca;
	while (*cp) {
		cout << *cp;
		++cp;
	}


	string s1("Momommo");
	string s2 = "nononon";

	if (s1 == s2) cout << "same string" << endl;
	else if (s1 > s2) cout << "s1 > s2" << endl;
	else cout << "s2 > s1" << endl;

	const char ch1[] = "c atring";
	const char ch2[] = "c string";
	const char* p1 = ch1;
	const char* p2 = ch2;

	auto result = strcmp(p1, p2);
	if (result == 0) cout << "equal" << endl;
	else if (result < 0) cout << "ch1 < ch2" << endl;
	else cout << "ch1 > ch2" << endl;

*/

	const char cstr1[] = "Hello";
	const char cstr2[] = "world!";

	size_t new_size = strlen(cstr1) + strlen(" ") + strlen(cstr2) + 1;
	char* cstr3 = new char[new_size];

	strcpy(cstr3, cstr1);
	strcat(cstr3, " ");
	strcat(cstr3, cstr2);

	std::cout << cstr3 << std::endl;
	delete[] cstr3;


	const int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> ivec(begin(arr), end(arr));
	int int_arr[10];

	for (int* i = begin(int_arr); i != end(int_arr); ++i)
		* i = ivec[i - begin(int_arr)];

	for (auto i : int_arr) std::cout << i << " ";
	std::cout << endl;

	return 0;
}


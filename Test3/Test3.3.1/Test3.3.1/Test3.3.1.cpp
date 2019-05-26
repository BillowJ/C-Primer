#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
/*	vector<int> v2;
	for (int i = 0; i != 100; ++i)
		v2.push_back(i);
	*/
	string n;
/*
	vector<string> text;
	while (cin >> n) {
		text.push_back(n);
		cout << text[text.size() - 1] << endl;
		for (auto i : n)
			cout << i << endl;
	}
    std::cout << "Hello World!\n"; 

	vector<unsigned>  scores(11, 0);
	unsigned grade;
	while (cin >> grade){
		if (grade <= 100)
			++scores[grade / 10];
		for (auto s : scores)
			cout << s << endl;
	}
	*/

/*	vector<int> v1;
	cout << "{\n \"v1\":{\"size\":\"" << v1.size() << "\",\"value\":[";
	for (auto i : v1) cout << i << ",";
	if (!v1.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v2(10);
	cout << " \"v2\":{\"size\":\"" << v2.size() << "\",\"value\":[";
	for (auto i : v2) cout << i << ",";
	if (!v2.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v3(10, 42);
	cout << " \"v3\":{\"size\":\"" << v3.size() << "\",\"value\":[";
	for (auto i : v3) cout << i << ",";
	if (!v3.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v4{ 10 };
	cout << " \"v4\":{\"size\":\"" << v4.size() << "\",\"value\":[";
	for (auto i : v4) cout << i << ",";
	if (!v4.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<int> v5{ 10, 42 };
	cout << " \"v5\":{\"size\":\"" << v5.size() << "\",\"value\":[";
	for (auto i : v5) cout << i << ",";
	if (!v5.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<string> v6{ 10 };
	cout << " \"v6\":{\"size\":\"" << v6.size() << "\",\"value\":[";
	for (auto i : v6)
		if (i.empty())
			cout << "(null)"
			<< ",";
		else
			cout << i << ",";
	if (!v6.empty()) cout << "\b";
	cout << "]}" << endl;

	vector<string> v7{ 10, "hi" };
	cout << " \"v7\":{\"size\":\"" << v7.size() << "\",\"value\":[";
	for (auto i : v7)
		if (i.empty())
			cout << "(null)"
			<< ",";
		else
			cout << i << ",";
	if (!v7.empty()) cout << "\b";
	cout << "]}\n}" << endl;
*/
/*
	vector<string> word;
	string input;
	while (cin >> input) 
		word.push_back(input);

		for (auto& str : word) 
			for (auto& c : str)
				c = toupper(c);
		
		for (decltype(word.size()) i = 0; i != word.size(); ++i) {
			if (i != 0 && i % 8 == 0) cout << endl;
			cout << word[i] << " ";
		}
		cout << endl;

*/
/*
		string s("something string.");
		if (s.begin() != s.end()) {
			auto it = s.begin();
			*it = toupper(*it);
		}


		for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
			* it = toupper(*it);
*/
/*
		int i;
		vector<int> ivec;
		while (cin >> i)ivec.push_back(i);

		if (ivec.empty()) {
			cout<<"input at least one integer"<<endl;
			return -1;
		}
		else if (ivec.size() == 1) {
			cout <<  *ivec.begin() << "has no adjancent elements.";
		}

		for (auto it = ivec.begin(); it + 1 != ivec.end(); ++it)
			cout << *it + *(it + 1) << " ";
		cout << endl;

		for (auto beg = ivec.begin(), end = ivec.end() - 1; beg <= end; ++beg, --end)
			cout << *beg + *end << " ";
		cout << endl;
	*/

	vector<int> iter(10,1);

	for (auto it = iter.begin(); it != iter.end(); ++it)
		*it *= 2;
	for (auto value : iter)
		cout << value << " ";
	cout << endl;

	return 0;

}


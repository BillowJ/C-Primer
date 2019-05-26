// Project9.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<deque>
#include<stack>
using namespace std;
int main()
{
/*	deque<int> deq;
	stack<int> stk(deq);
	//空栈
	stack<int> intStack;
	for (size_t ix = 0; ix != 10; ++ix) 
		intStack.push(ix); //保存10个数
		while (!intStack.empty()) {
			int value = intStack.top();
			intStack.pop();
		}*/
	auto& expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
	auto repl = '#';
	auto seen = 0;
	auto tmp = ' ';
	stack<char> stk;

	for (auto c : expr) {
		stk.push(c);
		if (c == '(') {
			++seen;
			stk.pop();
		}// open
		if (seen && c == ')') { // pop elements down to the stack
			stk.pop();      // including the open parenthesis
			stk.push(' ');
			--seen;         // close
		}
	}

	// Test
	string output;
	for (; !stk.empty(); stk.pop()) output.insert(output.begin(), stk.top());
	cout << output << endl; // "This is # and # over"


}

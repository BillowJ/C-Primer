#include <iostream>
using namespace std;

int main()
{
	int flag = 50;
	int sum = 0;
	while (flag < 100) {
		sum += flag;
		flag++;
	}
	cout << sum <<endl;
	int low, high;
	int sum1 = 0;
	cin >> low >> high;
	if (low >= high) {
		cerr << "error!" << endl;//endl will flush the output buffer
		return -1;
	}
	else{
		while (low<high){
			cout << low<<" "<<endl;
			++low;
		}
	}
	return 0;
}


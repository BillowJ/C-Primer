#include <iostream>
#include"ex7_24.h"
using namespace std;

int main()
{
	Screen myscreen(5, 5, 'x');
	myscreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myscreen.display(cout);
	cout << "\n";
}

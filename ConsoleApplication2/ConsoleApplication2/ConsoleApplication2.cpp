// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void main()
{
	int low = 0, high = 0;
	std::cin >> low >> high;
	int cont = 0;
	if (low > high){
		std::cout << "error" << std::endl;
		return;
	}
	else
	{
		cont = low;
		while (cont < high)
		{
			
			std::cout << "cont: " << cont
				<< std::endl;
			++cont;
		}
	}	
	return;
}



// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

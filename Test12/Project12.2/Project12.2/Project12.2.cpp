// Project12.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<memory>
#include<new>
using namespace std;

struct connection{
	string url;
	int port;
	connection(string _url, int _port) : url(_url), port(_port) {}
};
struct destination {
	
	string url;
	int port;
	destination(string _url, int _port) : url(_url), port(_port) {}
};

connection connect(destination* pDest) {
	shared_ptr<connection> pConn(new connection(pDest->url, pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")"
		<< std::endl;
	return *pConn;
}

void disconnect(connection pConn) {
	cout << "connection close(" << pConn.url << "：" << pConn.port << ")" << endl;
}

void end_connection(connection* c1) {
	disconnect(*c1);
}
void f(destination& d/*其他参数*/) {

	connection c = connect(&d);
	//使用unique_ptr替代shared_ptr
	unique_ptr<connection, decltype(end_connection)*> p1(&c, end_connection);
	shared_ptr<connection> p(&c, [](connection* c1) {
		disconnect(*c1); });
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
	destination dest("192.168.1.1", 80);
	destination dest1("192.168.1.1", 81);
	f(dest);
	f(dest1);
	typedef  unique_ptr<int>  IntP;
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	IntP p0(ix);
	IntP p1(pi);
	IntP p2(pi2);
	IntP p3(&ix);
	IntP p4(new int(2048));
	IntP p5(p2.get());
}


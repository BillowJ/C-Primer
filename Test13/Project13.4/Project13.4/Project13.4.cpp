// Project13.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

class Folders;
class Message {
public:
	friend void swap(Message&, Message&);
	friend void swap(Folders&, Folders&);
	friend class Folders;
public:
	explicit Message(const string& s = "") : contents(s) { }
	Message(const Message& msg) : contents(msg.contents), folders(msg.folders) {
		add_to_Folders(msg);
	}
	Message& operator = (const Message&);
	~Message();
public:
	void save(Folders&);
	void remove(Folders&);
	void print_debug();
private:
	string contents;
	set<Folders*> folders; //包含本Message的Folder
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folders* f) { folders.insert(f); }
	void remFldr(Folders* f) { folders.erase(f); }
};

class Folders {
public:
	friend void swap(Message&, Message&);
	friend void swap(Folders&, Folders&);
	friend class Message;
public:
	Folders() = default;
	Folders(const Folders&);
	Folders& operator = (const Folders&);
	~Folders();
	void print_debug();
	void swap(Folders&, Folders&);
	void addMsg(Message* m) {
		message.insert(m);
	}
	void removeMsg(Message* m) {
		message.erase(m);
	}
private:
	set<Message*> message;
	void remove_from_Message();
	void add_to_Message(const Folders&);
};

void Message::print_debug() {
	std::cout << contents << std::endl;
}

void Message::save(Folders& f) {
	addFldr(&f);
	f.addMsg(this);
}

void Message::remove(Folders& f) {
	folders.erase(&f);
	f.removeMsg(this);
}



void Message::add_to_Folders(const Message& msg) {
	for (auto f : msg.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_Folders() {
	for (auto f1 : folders) {
		f1->removeMsg(this);
	}
}

Message::~Message(){
		Message::remove_from_Folders();
}

Message& Message::operator = (const Message& mg) {
	remove_from_Folders();
	contents = mg.contents;
	folders = mg.folders;
	add_to_Folders(mg);
	return *this;
}

void swap(Message& lhs, Message& rhs) {
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);

	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}


void Folders::print_debug()
{
	for (auto m : message) std::cout << m->contents << " ";
	std::cout << std::endl;
}

void swap(Folders& lhs, Folders& rhs) {
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs, rhs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);

}
void Folders::add_to_Message(const Folders& f) {
	for (auto m : f.message) {
		m->addFldr(this);
	}
}

void Folders::remove_from_Message() {
	for (auto m : message) {
		m->folders.erase(this);
	}
}

Folders::~Folders() {
	remove_from_Message();
}

Folders& Folders::operator = (const Folders& f) {
	remove_from_Message();
	message = f.message;
	add_to_Message(f);
	return *this;
}

Folders::Folders(const Folders& f) : message(f.message)
{
	add_to_Message(f);
}

int main()
{
	Message firstMail("hello");
	Message signInMail("welcome to cppprimer");
	Folders mailBox;

	firstMail.print_debug(); // print: "hello"
	firstMail.save(mailBox); // send to mailBox
	mailBox.print_debug();   // print: "hello"

	signInMail.print_debug(); // print "welcome to cppprimer"
	signInMail.save(mailBox); // send to mailBox
	mailBox.print_debug();    // print "welcome to cppprimer hello"

	firstMail = firstMail;   // test for assignment to self.
	firstMail.print_debug(); // print "hello"
	mailBox.print_debug();   // print "welcome to cppprimer hello"
}

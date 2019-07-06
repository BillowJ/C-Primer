#pragma once
#ifndef CP5_ex13_49_Message_h
#define CP5_ex13_49_Message_h

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
	set<Folders*> folders; //°üº¬±¾MessageµÄFolder
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folders* f) { folders.insert(f); }
	void remFldr(Folders* f) { folders.erase(f); }
};

void swap(Message&, Message&);

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
	//void swap(Folders&, Folders&);
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

void swap(Folders&, Folders&);

#endif // CP5_ex13_49_Message_h
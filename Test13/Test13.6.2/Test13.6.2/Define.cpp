#include "ex13_49_Message.h"
#include<iostream>

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

Message::~Message() {
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

#pragma once
#ifndef CP5_ex7_23_h
#define CP5_ex7_23_h
#include<iostream>
#include<vector>
using namespace std;

class Screen;

class window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	vector<Screen> screen;
};

class Screen
{
	friend void window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
//	using pos = string::size_type;
	Screen() = default;//��Ϊ��Screen����һ�����캯�� ���Ա���ӵ��һ��Ĭ�ϵĹ��캯��
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	inline char get() const {
		return contents[cursor];
	}
	inline char get(pos r, pos c) const {
		return contents[r * width + c];
	}
	Screen& move(pos r, pos c);//�ⲿinline
	inline Screen& set(char);
	inline Screen& set(pos, pos, char);
	void some_member() const;
	Screen& display(std::ostream& os) { do_display(os); return *this; }
	//this -> const Screen* const
	const Screen& display(std::ostream& os) const { do_display(os); return *this; }
	pos size();
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr;
private:
	void do_display(std::ostream& os) const{ os << contents; }
};
//Ĭ�������һ��Window_mgt����һ����׼�Ŀհ�Screen


void window_mgr::clear(ScreenIndex i ){
	Screen& s = screen[i];
	s.contents = string(s.height * s.width, ' ');
}

window_mgr::ScreenIndex window_mgr::addScreen(const Screen& s) {
	screen.push_back(s);
	return screen.size() - 1;
}
inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
//���ù�굱ǰλ�õ�ֵ
//��ֵ����
Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
//���ù��ָ��λ�õ�ֵ
//��ֵ����
Screen& Screen::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}
//access_ctr Ϊmutual�����Ŀɱ��Ա
void Screen::some_member() const{
	++access_ctr;
}

Screen::pos Screen::size() {
	return width * height;
}
#endif // !CP5_ex7_23_h

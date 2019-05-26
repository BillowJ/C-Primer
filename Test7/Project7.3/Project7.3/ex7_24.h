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
	Screen() = default;//因为有Screen有另一个构造函数 所以必须拥有一个默认的构造函数
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	inline char get() const {
		return contents[cursor];
	}
	inline char get(pos r, pos c) const {
		return contents[r * width + c];
	}
	Screen& move(pos r, pos c);//外部inline
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
//默认情况，一个Window_mgt包含一个标准的空白Screen


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
//设置光标当前位置的值
//左值调用
Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
//设置光标指定位置的值
//左值调用
Screen& Screen::set(pos r, pos c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}
//access_ctr 为mutual声明的可变成员
void Screen::some_member() const{
	++access_ctr;
}

Screen::pos Screen::size() {
	return width * height;
}
#endif // !CP5_ex7_23_h

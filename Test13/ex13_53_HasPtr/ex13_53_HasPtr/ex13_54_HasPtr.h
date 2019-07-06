#pragma once
#ifndef EX13_54_HASPTR_H
#define EX13_54_HASPTR_H

#include<iostream>

class HasPtr {
	//public:friend void swap(HasPtr& lhp, HasPtr& rhp);
	//	   friend bool operator < (const HasPtr& lhs, const HasPtr& rhs);
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const std::string& s = std::string());
	HasPtr(const HasPtr& hap);
	HasPtr(HasPtr&& p) noexcept;
	HasPtr& operator = (const HasPtr&);
	HasPtr& operator = (HasPtr&& rhs) noexcept;
	//HasPtr& operator = (HasPtr rhs);
	~HasPtr();
private:
	std::string* ps;
	int i;
};

#endif // !EX13_54_HASPTR_H

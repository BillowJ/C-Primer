#pragma once
#ifndef CP5_ex7_57_h
#define CP5_ex7_57_h
#include<iostream>

class Account {
public:
	void caculate() { amount += amount * interestrate;}
	static double rate() { return interestrate; }
	static void rate(double& newRate) { interestrate = newRate; }
private:
	std::string ownner;
	double amount;
	static double interestrate;
	static constexpr double todayRate = 42.18;
	static double initRate() { return todayRate; }
};
double Account::interestrate = initRate();
#endif // !1

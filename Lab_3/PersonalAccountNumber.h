#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class PersonalAccountNumber
{
private:
	string numberOfPersonalAccount_;
	int cash_ = 0;

	string createPersonalAccountNumber();

public:
	void setNumberOfPersonalAccount();
	void setCash(int money);
	string getAccountNumber();
	int getCash();
};


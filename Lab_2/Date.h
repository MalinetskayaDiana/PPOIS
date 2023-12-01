#pragma once
#include <iostream>

using namespace std;

class Date
{
private:
	int month_;
	int year_;
public:

	void setDate(int month, int year);
	int getMonth();
	int getYear();
};


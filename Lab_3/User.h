#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
private:
	string userName_;
	string contactInfo_;

public:
	User();
	User(string name, string contactInfo);
	virtual void registration() = 0;

	string getUserName();
};


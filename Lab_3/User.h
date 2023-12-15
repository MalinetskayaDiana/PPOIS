#pragma once
#include "Cource.h"

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


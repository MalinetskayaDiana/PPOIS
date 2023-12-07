#pragma once
#include <iostream>
#include <string>

using namespace std;

class IndividTask
{
private:
	string assignment_;
	int grade_;
	string commentsOfInstructor_;

public:
	void setAssigment(string exercise);
	void setMark(int mark);
	void setComments(string comment);
	int getMark();
	string getComment();
};


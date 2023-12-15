#pragma once
#include "AdditionalMaterial.h"

class IndividTask
{
private:
	string assignment_;
	bool isComplite_ = false;
	string studentAnswer_;
	int grade_;
	string commentsOfInstructor_;

public:
	void setAssigment(string exercise);
	void setAnswer(string answer);
	void setMark(int mark);
	void setComments(string comment);
	void setComplite();
	string getAssigment();
	bool getComplite();
	string getAnswer();
	int getMark();
	string getComment();
};


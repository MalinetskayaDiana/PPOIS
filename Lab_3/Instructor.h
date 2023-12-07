#pragma once
#include "User.h"
#include "Cource.h"

class Instructor : virtual User
{
private:
	string nameOfTaughtCource_;
	string specialization_;
	int lengthOfService_;

	void setlengthOfService(int yearsOfWork);

public:
	Instructor();
	Instructor(string name, string specialization, int lengthOfService);

	void registration();
	void createLesson();
	void openAccessToLesson();
	void giveHomework();
	void checkHomework();
	int diveGrade();
};


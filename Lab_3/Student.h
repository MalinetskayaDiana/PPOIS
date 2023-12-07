#pragma once
#include "User.h"
#include "Cource.h"

class Student : virtual User
{
private:
	Cource studingCource_;
	string personalAccountNumber_;

public:
	Student();
	Student(string name);

	void registration() override;
	void comptiteLesson();
	void solveIndividTask();
	void payFor();
};


#pragma once
#include "User.h"

class Student : public User
{
private:
	Cource studingCource_;
	PersonalAccountNumber studentAccount_;
	bool isCertificate_ = false;

	void setAccountNumber();

public:
	Student();
	Student(string name, string personalInfo);

	void setCertificate();
	bool getCertificate();
	Cource& getStudingCource();
	PersonalAccountNumber& getAccount();

	void registration() override;
	void comptiteLesson();
	void solveIndividTask(string nameOfLesson, string studentAnswer);
	void payFor(int money);
};


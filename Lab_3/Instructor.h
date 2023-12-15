#pragma once
#include "Student.h"

class Instructor : virtual User
{
private:
	Cource TaughtCource_;
	string specialization_;
	int lengthOfService_;

	void setlengthOfService(int yearsOfWork);

public:
	Instructor();
	Instructor(string name, string personalInfo, string specialization, int lengthOfService);

	Cource& getTaughtCource();

	void registration() override;
	void createLesson(string nameOfLesson, string topicOfLesson);
	void attachTextMaterial(string nameOfLesson, string text);
	void attachVideoMaterial(string nameOfLesson, string link);
	void attachAdditionalMaterial(string nameOfLesson, string link);
	void openAccessToLesson(string nameOfLesson);
	void giveHomework(string nameOfLesson, string assigment);
	void checkHomework(string nameOfLesson, int mark, string comment);
};


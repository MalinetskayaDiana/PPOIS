#include "Student.h"

void Student::setAccountNumber()
{
	studentAccount_.setNumberOfPersonalAccount();
}

Student::Student(){}

Student::Student(string name, string personalInfo) : User(name, personalInfo) {}

void Student::setCertificate()
{
	isCertificate_ = true;
}

bool Student::getCertificate()
{
	return isCertificate_;
}

Cource& Student::getStudingCource()
{
	return studingCource_;
}

PersonalAccountNumber& Student::getAccount()
{
	return studentAccount_;
}

void Student::registration()
{
	setAccountNumber();
}

void Student::comptiteLesson()
{
	int numberOfLesson = studingCource_.CalculationOfNumberOfLearnedLesson() + 1;
	Lesson nowLesson = studingCource_.getLesson(numberOfLesson);
	if (nowLesson.getAccessToLesson())
	{
		if ((nowLesson.getHomework().getMark() > 5) && (nowLesson.getTextMaterial().getIsExamined()) &&
			(nowLesson.getVideoMaterial().getIsExamined()))
		{
			studingCource_.setListOfLearnedLessons(nowLesson);
		}
	}
}

void Student::solveIndividTask(string nameOfLesson, string studentAnswer)
{
	int numberOfLesson = studingCource_.searchOfLesson(nameOfLesson);
	studingCource_.getLesson(numberOfLesson).getHomework().setAnswer(studentAnswer);
	studingCource_.getLesson(numberOfLesson).getHomework().setComplite();
}

void Student::payFor(int money)
{
	studentAccount_.setCash(money);
}

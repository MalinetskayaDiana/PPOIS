#include "Student.h"

Student::Student(){}

Student::Student(string name) : User(name) {}

void Student::registration()
{
	cout << "I'm student";
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

		}
	}
}
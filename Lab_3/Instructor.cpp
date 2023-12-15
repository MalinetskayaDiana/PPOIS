#include "Instructor.h"

void Instructor::setlengthOfService(int yearsOfWork)
{
	if(yearsOfWork < 0 || yearsOfWork > 60)
		throw invalid_argument("How old would he be then?");
	else
		lengthOfService_ = yearsOfWork;
}

Instructor::Instructor(){}

Instructor::Instructor(string name, string personalInfo, string specialization, int lengthOfService) : User(name, personalInfo)
{
	specialization_ = specialization;
	setlengthOfService(lengthOfService);
}

Cource& Instructor::getTaughtCource()
{
	return TaughtCource_;
}

void Instructor::registration(){}

void Instructor::createLesson(string nameOfLesson, string topicOfLesson)
{
	Lesson newLesson(nameOfLesson, topicOfLesson);
	TaughtCource_.setListOfLessons(newLesson);
}

void Instructor::attachTextMaterial(string nameOfLesson, string text)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).setTextOfLesson(text);
}

void Instructor::attachVideoMaterial(string nameOfLesson, string link)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).setListOfVideo(link);
}

void Instructor::attachAdditionalMaterial(string nameOfLesson, string link)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).setAddMaterial(link);
}

void Instructor::openAccessToLesson(string nameOfLesson)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).setAccessToLesson();
}

void Instructor::giveHomework(string nameOfLesson, string assigment)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).setHomework(assigment);
}

void Instructor::checkHomework(string nameOfLesson, int mark, string comment)
{
	int numberOfLesson = TaughtCource_.searchOfLesson(nameOfLesson);
	TaughtCource_.getLesson(numberOfLesson).getHomework().setMark(mark);
	TaughtCource_.getLesson(numberOfLesson).getHomework().setComments(comment);
}
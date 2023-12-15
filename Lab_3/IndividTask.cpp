#include "IndividTask.h"

void IndividTask::setAssigment(string exercise)
{
	assignment_ = exercise;
}

void IndividTask::setAnswer(string answer)
{
	studentAnswer_ = answer;
}

void IndividTask::setMark(int mark)
{
	if (mark < 1 || mark > 10)
		throw invalid_argument("We have ten-point system");
	else
		grade_ = mark;
}

void IndividTask::setComments(string comment)
{
	commentsOfInstructor_ = comment;
}

void IndividTask::setComplite()
{
	isComplite_ = true;
}

string IndividTask::getAssigment()
{
	return assignment_;
}

bool IndividTask::getComplite()
{
	return isComplite_;
}

string IndividTask::getAnswer()
{
	return studentAnswer_;
}

int IndividTask::getMark()
{
	return grade_;
}

string IndividTask::getComment()
{
	return commentsOfInstructor_;
}

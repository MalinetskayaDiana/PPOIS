#include "Cource.h"

Cource::Cource(){}

Cource::Cource(string courceName, string courceTopic, string instructorName) : nameOfCource_(courceName), courceTopic_(courceTopic), instructorName_(instructorName){}

void Cource::setListOfLessons(Lesson& lesson)
{
	listOfLessons_.push_back(lesson);
}

void Cource::setListOfLearnedLessons(Lesson& lesson)
{
	learnedLessons_.push_back(lesson);
}

string Cource::getNameOfCource()
{
	return nameOfCource_;
}

string Cource::getCourceTopic()
{
	return courceTopic_;
}

Lesson Cource::getLesson(int lessonNumber)
{
	return listOfLessons_[lessonNumber];
}

string Cource::getInctructorNameOfCource()
{
	return instructorName_;
}

int Cource::CalculationOfNumberOfAllLesson()
{
	int countOfAllLessons = 0;
	for (Lesson i : listOfLessons_) 
	{
		countOfAllLessons++;
	}
	return countOfAllLessons;
}

int Cource::CalculationOfNumberOfLearnedLesson()
{
	int countOfLearnedLessons = 0;
	for (Lesson i : learnedLessons_)
	{
		countOfLearnedLessons++;
	}
	return countOfLearnedLessons;
}

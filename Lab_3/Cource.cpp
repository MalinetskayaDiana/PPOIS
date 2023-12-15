#include "Cource.h"

Cource::Cource(){}

Cource::Cource(string courceName, string courceTopic) : nameOfCource_(courceName), courceTopic_(courceTopic){}

void Cource::setNameOfCource(string nameOfCource)
{
	nameOfCource_ = nameOfCource;
}

void Cource::setTopicOfCource(string topicOfCource)
{
	courceTopic_ = topicOfCource;
}

void Cource::setListOfLessons(Lesson& lesson)
{
	listOfLessons_.push_back(lesson);
}

void Cource::setListOfLearnedLessons(Lesson& lesson)
{
	learnedLessons_.push_back(lesson);
}

void Cource::setInstructor(string nameOfInstructor)
{
	instructorName_ = nameOfInstructor;
}

vector<Lesson>& Cource::getListOfAllLessons()
{
	return listOfLessons_;
}

string Cource::getNameOfCource()
{
	return nameOfCource_;
}

string Cource::getCourceTopic()
{
	return courceTopic_;
}

Lesson& Cource::getLesson(int lessonNumber)
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

int Cource::searchOfLesson(string nameOfLesson)
{
	int countOfLesson = 0;
	for (Lesson i : listOfLessons_) 
	{
		if (i.getNameOfLesson() == nameOfLesson)
			break;
		else
			countOfLesson++;
	}
	if (countOfLesson > listOfLessons_.size())
		throw invalid_argument("This lesson not exist!");
	else
		return countOfLesson;
}

void Cource::resetProgress()
{
	learnedLessons_.erase(learnedLessons_.begin(), learnedLessons_.end());
}

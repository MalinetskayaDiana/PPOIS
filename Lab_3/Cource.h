#pragma once
#include <vector>
#include "Lesson.h"

class Cource
{
private:
	string nameOfCource_;
	string courceTopic_;
	vector<Lesson> listOfLessons_;
	vector<Lesson> learnedLessons_;
	string instructorName_;

public:
	Cource();
	Cource(string courceName,string courceTopic, string instructorName);

	void setListOfLessons(Lesson& lesson);
	void setListOfLearnedLessons(Lesson& lesson);
	string getNameOfCource();
	string getCourceTopic();
	Lesson getLesson(int lessonNumber);
	string getInctructorNameOfCource();
	int CalculationOfNumberOfAllLesson();
	int CalculationOfNumberOfLearnedLesson();
};


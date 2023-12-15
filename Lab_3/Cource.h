#pragma once
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
	Cource(string courceName,string courceTopic);

	void setNameOfCource(string nameOfCource);
	void setTopicOfCource(string topicOfCource);
	void setListOfLessons(Lesson& lesson);
	void setListOfLearnedLessons(Lesson& lesson);
	void setInstructor(string nameOfInstructor);
	vector<Lesson>& getListOfAllLessons();
	string getNameOfCource();
	string getCourceTopic();
	Lesson& getLesson(int lessonNumber);
	string getInctructorNameOfCource();

	int CalculationOfNumberOfAllLesson();
	int CalculationOfNumberOfLearnedLesson();
	int searchOfLesson(string nameOfLesson);
	void resetProgress();
};


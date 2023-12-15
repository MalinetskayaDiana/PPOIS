#include "HumanResources.h"

void HumanResources::setStudentList(Student& student)
{
	listOfStudents_.push_back(student);
}

void HumanResources::setInstuctorList(Instructor& instructor)
{
	listOfInstructors_.push_back(instructor);
}

void HumanResources::setCourceList(Cource& cource)
{
	listOfCourse_.push_back(cource);
}

void HumanResources::createCource(string nameOfCource, string topicOfCource)
{
	Cource newCource(nameOfCource, topicOfCource);
	setCourceList(newCource);
}

string HumanResources::courseSelection(string searchingTopic)
{
	string nameOfCource;
	for (Cource i : listOfCourse_) 
	{
		if (i.getCourceTopic() == searchingTopic) 
		{
			nameOfCource = i.getNameOfCource();
			break;
		}
	}
	if (nameOfCource == "")
		throw invalid_argument("No such cource");
	else
		return nameOfCource;
}

Cource& HumanResources::searchCource(string nameOfCource)
{
	for (Cource i : listOfCourse_)
	{
		if (i.getNameOfCource() == nameOfCource)
		{
			return i;
			break;
		}
		if (&i == &listOfCourse_.back()) 
		{
			throw invalid_argument("No such cource");
		}
	}
}

void HumanResources::demandPayment(string studentAccount, int payment)
{
	for (Student i : listOfStudents_) 
	{
		if (i.getAccount().getAccountNumber() == studentAccount)
		{
			i.payFor(payment);
		}
	}
}

void HumanResources::certify(string nameOfStudent)
{
	for (Student i : listOfStudents_)
	{
		if (i.getUserName() == nameOfStudent && i.getStudingCource().CalculationOfNumberOfAllLesson() == i.getStudingCource().CalculationOfNumberOfLearnedLesson())
		{
			i.setCertificate();
		}
	}
}

void HumanResources::transferToCource(Student& student, string searchingTopic)
{
	string nameOfCource = courseSelection(searchingTopic);
	student.getStudingCource().setNameOfCource(nameOfCource);
	student.getStudingCource().setTopicOfCource(searchingTopic);
	vector<Lesson> newLessonCource = searchCource(nameOfCource).getListOfAllLessons();
	string nameOfInstructor = searchCource(nameOfCource).getInctructorNameOfCource();
	student.getStudingCource().getListOfAllLessons().assign(newLessonCource.begin(), newLessonCource.end());
	student.getStudingCource().resetProgress();
	student.getStudingCource().setInstructor(nameOfInstructor);
}
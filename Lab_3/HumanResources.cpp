#include "HumanResources.h"

void HumanResources::setStudentList(Student student)
{
	listOfStudents_.push_back(student);
}

void HumanResources::setInstuctorList(Instructor instructor)
{
	listOfInstructors_.push_back(instructor);
}

void HumanResources::setCourceList(Cource cource)
{
	listOfCourse_.push_back(cource);
}

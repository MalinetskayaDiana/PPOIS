#pragma once
#include <vector>
#include "Student.h"
#include "Instructor.h"
#include "Cource.h"

class HumanResources
{
private:
	vector<Student> listOfStudents_;
	vector<Instructor> listOfInstructors_;
	vector<Cource> listOfCourse_;

public:
	void setStudentList(Student student);
	void setInstuctorList(Instructor instructor);
	void setCourceList(Cource cource);

	void createCource();
	void courseSelection();
	void demandPayment();
	void certify();
	void solveProblems();
};


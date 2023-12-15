#pragma once
#include "Instructor.h"

class HumanResources
{
private:
	vector<Student> listOfStudents_;
	vector<Instructor> listOfInstructors_;
	vector<Cource> listOfCourse_;

public:
	void setStudentList(Student& student);
	void setInstuctorList(Instructor& instructor);
	void setCourceList(Cource& cource);

	void createCource(string nameOfCource, string topicOfCource);
	string courseSelection(string searchingTopic);
	Cource& searchCource(string nameOfCource);
	void demandPayment(string studentAccount, int payment);
	void certify(string nameOfStudent);
	void transferToCource(Student& student, string searchingTopic);
};


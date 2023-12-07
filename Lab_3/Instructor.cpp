#include "Instructor.h"

void Instructor::setlengthOfService(int yearsOfWork)
{
	if(yearsOfWork < 0 || yearsOfWork > 60)
		throw invalid_argument("How old would he be then?");
	else
		lengthOfService_ = yearsOfWork;
}

Instructor::Instructor(){}

Instructor::Instructor(string name, string specialization, int lengthOfService) : User(name)
{
	specialization_ = specialization;
	setlengthOfService(lengthOfService);
}

void Instructor::registration()
{
	cout << "I'm instructor";
}

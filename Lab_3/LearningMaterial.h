#pragma once
#include "PersonalAccountNumber.h"

class LearningMaterial
{
private:
	string nameOfMaterial_;
	bool isExamined_ = 0;

public:
	LearningMaterial();
	LearningMaterial(string nameOfMaterial);

	void setIsExamineted();
	string getNameOfMaterial();
	bool getIsExamined();
};


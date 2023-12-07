#pragma once
#include <string>
#include <iostream>

using namespace std;

class LearningMaterial
{
private:
	string nameOfMaterial_;
	bool isExamined_;

public:
	LearningMaterial();
	LearningMaterial(string nameOfMaterial, bool isDone);

	void setIsExamineted();
	string getNameOfMaterial();
	bool getIsExamined();
};


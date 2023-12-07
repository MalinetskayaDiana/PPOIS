#include "LearningMaterial.h"

LearningMaterial::LearningMaterial(){}

LearningMaterial::LearningMaterial(string nameOfMaterial, bool): nameOfMaterial_(nameOfMaterial), isExamined_(false){}

void LearningMaterial::setIsExamineted()
{
	isExamined_ = true;
}

string LearningMaterial::getNameOfMaterial()
{
	return nameOfMaterial_;
}

bool LearningMaterial::getIsExamined()
{
	return isExamined_;
}

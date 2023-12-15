#include "LearningMaterial.h"

LearningMaterial::LearningMaterial(){}

LearningMaterial::LearningMaterial(string nameOfMaterial): nameOfMaterial_(nameOfMaterial){}

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

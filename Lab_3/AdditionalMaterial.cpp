#include "AdditionalMaterial.h"

AdditionalMaterial::AdditionalMaterial(){}

AdditionalMaterial::AdditionalMaterial(string nameOfMaterial) : LearningMaterial(nameOfMaterial){}

void AdditionalMaterial::setLink(string link)
{
	linkOfAddMaterial_ = link;
}

string AdditionalMaterial::getLink()
{
	return linkOfAddMaterial_;
}

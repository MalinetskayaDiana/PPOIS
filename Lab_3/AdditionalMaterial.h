#pragma once
#include "LearningMaterial.h"

class AdditionalMaterial : public LearningMaterial
{
private:
	string linkOfAddMaterial_;

public:
	void setLink(string link);
	string getLink();
};


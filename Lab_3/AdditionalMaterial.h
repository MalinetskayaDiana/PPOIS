#pragma once
#include "VideoMaterial.h"

class AdditionalMaterial : public LearningMaterial
{
private:
	string linkOfAddMaterial_;

public:
	AdditionalMaterial();
	AdditionalMaterial(string nameOfMaterial);

	void setLink(string link);
	string getLink();
};


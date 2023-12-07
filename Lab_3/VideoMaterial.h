#pragma once
#include "LearningMaterial.h"

class VideoMaterial : public LearningMaterial
{
private:
	string linkOfVideo_;

public:
	void setLink(string link);
	string getLink();
};


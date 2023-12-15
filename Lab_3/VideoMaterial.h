#pragma once
#include "TextMaterial.h"

class VideoMaterial : public LearningMaterial
{
private:
	string linkOfVideo_;

public:
	VideoMaterial();
	VideoMaterial(string nameOfVideo);

	void setLink(string link);
	string getLink();
};


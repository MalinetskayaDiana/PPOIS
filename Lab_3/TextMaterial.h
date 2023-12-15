#pragma once
#include "LearningMaterial.h"

class TextMaterial: public LearningMaterial
{
private:
	string materialText_;

public:
	TextMaterial();
	TextMaterial(string nameOfMaterial);

	void setTextMaterial(string text);
	string getTextMeterial();
};


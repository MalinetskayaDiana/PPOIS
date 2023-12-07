#pragma once
#include "LearningMaterial.h"

class TextMaterial: public LearningMaterial
{
private:
	string materialText_;

public:
	TextMaterial();
	TextMaterial(string nameOfMaterial, bool isDone, string text);

	void setTextMaterial(string text);
	string getTextMeterial();
};


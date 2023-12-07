#include "TextMaterial.h"

TextMaterial::TextMaterial(){}

TextMaterial::TextMaterial(string nameOfMaterial, bool isDone, string text) : LearningMaterial(nameOfMaterial, isDone)
{
	setTextMaterial(text);
}

void TextMaterial::setTextMaterial(string text)
{
	materialText_ = text;
}

string TextMaterial::getTextMeterial()
{
	return materialText_;
}

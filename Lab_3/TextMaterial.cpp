#include "TextMaterial.h"

TextMaterial::TextMaterial(){}

TextMaterial::TextMaterial(string nameOfMaterial) : LearningMaterial(nameOfMaterial){}

void TextMaterial::setTextMaterial(string text)
{
	materialText_ = text;
}

string TextMaterial::getTextMeterial()
{
	return materialText_;
}

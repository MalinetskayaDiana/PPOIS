#include "Lesson.h"

Lesson::Lesson(){}

Lesson::Lesson(string nameOfLesson, string lessonTopic) : nameOfLesson_(nameOfLesson), lessonTopic_(lessonTopic){}

void Lesson::setAccessToLesson()
{
	accessToLesson_ = true;
}

void Lesson::setTextOfLesson(string text)
{
	textOfLesson_.setTextMaterial(text);
}

void Lesson::setListOfVideo(string linkOfVideo)
{
	listOfVideo_.setLink(linkOfVideo);
}

void Lesson::setAddMaterial(string linkOfAddMaterial)
{
	AdditionalMaterial usefullLink;
	usefullLink.setLink(linkOfAddMaterial);
	addMaterial_.push_back(usefullLink);
}

void Lesson::setHomework(string exercise)
{
	homework_.setAssigment(exercise);
}

string Lesson::getNameOfLesson()
{
	return nameOfLesson_;
}

string Lesson::getLessonTopic()
{
	return lessonTopic_;
}

bool Lesson::getAccessToLesson()
{
	return accessToLesson_;
}

TextMaterial Lesson::getTextMaterial()
{
	return textOfLesson_;
}

VideoMaterial Lesson::getVideoMaterial()
{
	return listOfVideo_;
}

IndividTask Lesson::getHomework()
{
	return homework_;
}


#pragma once
#include <vector>
#include "IndividTask.h"
#include "TextMaterial.h"
#include "VideoMaterial.h"
#include "AdditionalMaterial.h"

class Lesson
{
private:
	string nameOfLesson_;
	string lessonTopic_;
	bool accessToLesson_ = false;
	TextMaterial textOfLesson_;
	VideoMaterial listOfVideo_;
	vector<AdditionalMaterial> addMaterial_;
	IndividTask homework_;

public:
	Lesson();
	Lesson(string nameOfLesson, string lessonTopic);
	void setAccessToLesson();
	void setTextOfLesson(string text);
	void setListOfVideo(string linkOfVideo);
	void setAddMaterial(string linkOfAddMaterial);
	void setHomework(string exercise);
	string getNameOfLesson();
	string getLessonTopic();
	bool getAccessToLesson();
	TextMaterial getTextMaterial();
	VideoMaterial getVideoMaterial();
	IndividTask getHomework();
};


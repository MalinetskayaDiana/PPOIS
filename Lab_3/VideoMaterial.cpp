#include "VideoMaterial.h"

VideoMaterial::VideoMaterial(){}

VideoMaterial::VideoMaterial(string nameOfVideo) : LearningMaterial(nameOfVideo){}

void VideoMaterial::setLink(string link)
{
	linkOfVideo_ = link;
}

string VideoMaterial::getLink()
{
	return linkOfVideo_;
}

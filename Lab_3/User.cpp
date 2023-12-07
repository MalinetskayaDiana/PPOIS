#include "User.h"

User::User(){}

User::User(string name, string contactInfo) : userName_(name), contactInfo_(contactInfo){}

string User::getUserName()
{
	return userName_;
}

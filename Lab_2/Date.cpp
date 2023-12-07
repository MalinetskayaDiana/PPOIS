#include "Date.h"

void Date::setDate(int month, int year)
{
	if (month < 0 || month > 12)
		throw invalid_argument("Invalid number format");
	else if (year < 2016 || year > 2030)
		throw invalid_argument("Invalid number format");
	else 
	{
		month_ = month;
		year_ = year;
	}
}

int Date::getMonth()
{
	return month_;
}

int Date::getYear()
{
	return year_;
}
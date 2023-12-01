#include "Date.h"

void Date::setDate(int month, int year)
{
	try
	{
		if (month < 0 || month > 12)
			throw invalid_argument("Invalid number format");
		if (year < 2016 || year > 2030)
			throw invalid_argument("Invalid number format");
		month_ = month;
		year_ = year;
	}
	catch (const invalid_argument& error)
	{
		cout << error.what() << endl;
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
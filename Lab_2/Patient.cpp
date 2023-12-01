#include "Patient.h"

Patient::Patient(string name, int age, int weight, float discount, int money) : Human(name)
{
	age_ = setAge(age);
	weight_ = setWeight(weight);
	cureDiscount_ = setDiscount(discount);
	setMoney(money);
}

int Patient::setAge(int age)
{
	try
	{
		if (age < 0 && age > 110)
			throw invalid_argument("Invalid number format");
		return age;
	}
	catch (const invalid_argument& error)
	{
		cout << error.what() << endl;
	}
}

int Patient::setWeight(int weight)
{
	try
	{
		if (weight < 0 && weight > 200)
			throw invalid_argument("Invalid number format");
		return weight;
	}
	catch (const invalid_argument& error)
	{
		cout << error.what() << endl;
	}
}

float Patient::setDiscount(float discount)
{
	try
	{
		if (discount < 0 && discount > 1)
			throw invalid_argument("Invalid number format");
		return discount;
	}
	catch (const invalid_argument& error)
	{
		cout << error.what() << endl;
	}
}

void Patient::setListOfNeededCure(Cure drug)
{
	listOfNeededCure_.push_back(drug);
}

float Patient::getDiscount()
{
	return cureDiscount_;
}

int Patient::getWeight()
{
	return weight_;
}

int Patient::getAge()
{
	return age_;
}

string Patient::getSymptoms()
{
	for (string i : symptoms_)
	return i;
}

void Patient::setSymptoms(string symptom)
{
	symptoms_.push_back(symptom);
}

void Patient::setMoney(int money)
{
	try
	{
		if (money < 0)
			throw invalid_argument("Invalid number format");
		money_ = money;
	}
	catch (const invalid_argument& error)
	{
		cout << error.what() << endl;
	}
}

int Patient::payForCure()
{
	return money_;
}
#pragma once
#include "Human.h"
#include "Cure.h"
#include "Doctor.h"

class Patient: public Human
{
private:
	int age_;
	int weight_;
	vector<string> symptoms_;
	vector<Cure> listOfNeededCure_;
	int money_;
	float cureDiscount_;

	int setAge(int age);
	int setWeight(int weight);
	float setDiscount(float discount);

public:
	Patient(string name, int age, int weight, float discount, int money);

	void setListOfNeededCure(Cure drug);
	float getDiscount();
	int getWeight();
	int getAge();
	string getSymptoms();
	void setSymptoms(string symptom);
	void setMoney(int money);
	int payForCure();
};


#pragma once
#include "Cure.h"
#include "Patient.h"

class Doctor: public Human
{
private:
	vector<Cure> knownCure_;
	vector<string> patientSymptoms_;
public:
	Doctor(string name);

	void setPatientSymptoms(string symptom);
	void setNewDrug(Cure drug);
	Cure prescribeDrugs();
	int giveDose(int patientWeight, int doseInDay);
	string getPatientSymptoms();
	Cure getknowledgeOfCure();
};


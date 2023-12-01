#include "Doctor.h"

Doctor::Doctor(string name) : Human(name) {}

void Doctor::setPatientSymptoms(string symptom)
{
	patientSymptoms_.push_back(symptom);
}

void Doctor::setNewDrug(Cure drug)
{
	knownCure_.push_back(drug);
}

Cure Doctor::prescribeDrugs()
{
	for (Cure i : knownCure_)
		for (string j : patientSymptoms_)
			if (i.getScopeOfApplication() == j)
				return i;
}

int Doctor::giveDose(int patientWeight, int doseInDay)
{
	return doseInDay * patientWeight;
}

string Doctor::getPatientSymptoms()
{
	for (string i : patientSymptoms_)
		return i;
}

Cure Doctor::getknowledgeOfCure()
{
	for (Cure i : knownCure_)
	return i;
}

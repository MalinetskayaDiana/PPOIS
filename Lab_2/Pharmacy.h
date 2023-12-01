#pragma once
#include "Patient.h"
#include "CashierOffice.h"

class Pharmacy
{
private:
	vector<Cure> accessCure_;
	vector<Cure> neededCure_;
	CashierOffice check_;

public:
	bool needMoreCure();
	void cureSale(Patient &patient);
	void searchCure(string nameOfCure);
	Cure searchAlternative(Cure drug);
	void unloadingOfCure(Cure drug);
	Cure orderCure();
	void checkForExpirationDate(Date today);
	CashierOffice getCheck();
	Cure getAccessCure();
};


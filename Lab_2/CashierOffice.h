#pragma once
#include "Cure.h"

class CashierOffice
{
private:
	int totalPrice_ = 0;
	vector<Cure> listOfPurchasedMedicine_;

	void cureDiscount(float discount);

public:

	bool checkIsEmpty();
	int getTotalPrice();
	void setListOfPurchasedMedicine(Cure drug);
	Cure returnCure();
	int totalPriceCalculation(float discount);
	int changeCalculation(int payment, float discount);
};


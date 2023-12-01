#pragma once
#include <vector>
#include "Date.h"
#include "ActiveIngredient.h"

class Cure
{
private:
	string nameOfCure_;
	Date dateOfProduction_;
	Date expirationDate_;
	ActiveIngredient ingredients_;
	string scopeOfApplication_;
	int priceOfCure_;

public:
	Cure(){}
	Cure(string name, Date producted, Date cureLife, ActiveIngredient ingredient, string scope, int price);

	void setCurePrice(int price);
	Date getDateOfProduction();
	Date getExpirationDate();
	ActiveIngredient getIngredirnt();
	string getNameOfCure();
	string getScopeOfApplication();
	int getPriceOfCure();
};


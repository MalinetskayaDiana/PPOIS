#include "Cure.h"

Cure::Cure(string name, Date producted, Date cureLife, ActiveIngredient ingredient, string scope, int price)
{
	nameOfCure_ = name;
	dateOfProduction_ = producted;
	expirationDate_ = cureLife;
	ingredients_ = ingredient;
	scopeOfApplication_ = scope;
	setCurePrice(price);
}

void Cure::setCurePrice(int price)
{
	priceOfCure_ = price;
}

Date Cure::getDateOfProduction()
{
	return dateOfProduction_;
}

Date Cure::getExpirationDate()
{
	return expirationDate_;
}

ActiveIngredient Cure::getIngredirnt()
{
	return ingredients_;
}

string Cure::getNameOfCure()
{
	return nameOfCure_;
}

string Cure::getScopeOfApplication()
{
	return scopeOfApplication_;
}

int Cure::getPriceOfCure()
{
	return priceOfCure_;
}
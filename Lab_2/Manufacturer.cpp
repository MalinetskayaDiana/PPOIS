#include "Manufacturer.h"

Manufacturer::Manufacturer(){}
Manufacturer::Manufacturer(string nameOfCompany, string country, int companyProfit) : nameOfManufacture_(nameOfCompany), countryOfManufacture_(country), percentageOfManucature_(companyProfit) {}

int Manufacturer::manufacturePrice(int ingredientPrice)
{
	return ingredientPrice + ingredientPrice * percentageOfManucature_;
}

void Manufacturer::createNewCure(string name, Date today, Date cureLife, ActiveIngredient ingredient, string scope)
{
	Cure drug(name, today, cureLife, ingredient, scope, manufacturePrice(ingredient.getIngredientPrice()));
	listOfManufacturedCure_.push_back(drug);
}

void Manufacturer::supplyOfMedicine(Cure cure, Pharmacy& pharmacy)
{
	pharmacy.unloadingOfCure(cure);
}

bool Manufacturer::isProduceCure(Cure cure)
{
	bool isProduced = false;
	for (Cure i : listOfManufacturedCure_)
		if (i.getNameOfCure() == cure.getNameOfCure()
			&& i.getIngredirnt().getIngredientName() == cure.getIngredirnt().getIngredientName()
			&& i.getScopeOfApplication() == cure.getScopeOfApplication())
		{
			isProduced = true;
		}
	return isProduced;
}

Cure Manufacturer::getCure(string nameOfCure)
{
	for (Cure i : listOfManufacturedCure_)
	{
		if (i.getNameOfCure() == nameOfCure)
			return i;
	}
}

bool Manufacturer::complianceQuality(Cure& cure, int standardOfmass)
{
	if (cure.getIngredirnt().getIngredientMass() == standardOfmass) return true;
	else return false;
}

string Manufacturer::getNameOfManufacturer()
{
	return nameOfManufacture_;
}

string Manufacturer::getCountryOfManufacturer()
{
	return countryOfManufacture_;
}

int Manufacturer::getPercentageOfManufacturer()
{
	return percentageOfManucature_;
}

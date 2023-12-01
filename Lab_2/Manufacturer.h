#pragma once
#include "Cure.h"
#include "Pharmacy.h"

class Manufacturer
{
private:
	string nameOfManufacture_;
	string countryOfManufacture_;
	int percentageOfManucature_;
	vector<Cure> listOfManufacturedCure_;

	int manufacturePrice(int ingredientPrice);

public:
	Manufacturer();
	Manufacturer(string nameOfCompany, string country, int companyProfit);

	void createNewCure(string name, Date today, Date cureLife, ActiveIngredient ingredient, string scope);
	void supplyOfMedicine(Cure cure, Pharmacy& pharmacy);
	bool isProduceCure(Cure cure);
	Cure getCure(string nameOfCure);
	bool complianceQuality(Cure& cure, int standardOfmass);
	string getNameOfManufacturer();
	string getCountryOfManufacturer();
	int getPercentageOfManufacturer();

};


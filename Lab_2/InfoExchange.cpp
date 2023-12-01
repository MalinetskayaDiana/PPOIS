#include "InfoExchange.h"

Manufacturer InfoExchange::searchManucaturer(Cure drug)
{
	for (Manufacturer i : listOfManufacturers_)
	{
		if (i.isProduceCure(drug))
			return i;
	}
}

void InfoExchange::setListOfManucaturer(Manufacturer& manucaturer)
{
	listOfManufacturers_.push_back(manucaturer);
}

void InfoExchange::setNewDoctor(Doctor& doctor)
{
	doctors_.push_back(doctor);
}

void InfoExchange::setListOfPharmacy(Pharmacy& pharmacy)
{
	pharmacy_ = pharmacy;
}

void InfoExchange::takeOrderPharmacy(Pharmacy& pharmacy)
{
	Cure drug = pharmacy.orderCure();
	Manufacturer manufacture;
	if (manufacture.isProduceCure(drug))
	{
		manufacture.supplyOfMedicine(drug, pharmacy);
	}
}

void InfoExchange::informationToDoctors(Cure& cure)
{
	for (Doctor i : doctors_)
	{
		i.setNewDrug(cure);
	}
}

Manufacturer InfoExchange::getListOfManucaturer()
{
	for (Manufacturer i : listOfManufacturers_)
	return i;
}

Doctor InfoExchange::getDoctor()
{
	for (Doctor i : doctors_)
	return i;
}

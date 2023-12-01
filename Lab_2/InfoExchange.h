#pragma once
#include "Manufacturer.h"
#include "Doctor.h"

class InfoExchange
{
private:
	vector<Manufacturer> listOfManufacturers_;
	vector<Doctor> doctors_;
	Pharmacy pharmacy_;

	Manufacturer searchManucaturer(Cure drug);

public:
	void setListOfManucaturer(Manufacturer& manucaturer);
	void setNewDoctor(Doctor& doctor);
	void setListOfPharmacy(Pharmacy& pharmacy);
	void takeOrderPharmacy(Pharmacy& pharmacy);
	void informationToDoctors(Cure& cure);
	Manufacturer getListOfManucaturer();
	Doctor getDoctor();
};


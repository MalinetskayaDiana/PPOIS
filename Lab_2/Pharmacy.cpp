#include "Pharmacy.h"

bool Pharmacy::needMoreCure()
{
	if (!neededCure_.empty())
		return true;
	else
		return false;
}

void Pharmacy::cureSale(Patient &patient)
{
	int totalPrice = check_.totalPriceCalculation(patient.getDiscount());
	if (totalPrice > patient.payForCure())
	{
		while (!check_.checkIsEmpty())
			unloadingOfCure(check_.returnCure());
	}
	else 
	{
		patient.setMoney(getCheck().changeCalculation(totalPrice, patient.getDiscount()));
	}
}

void Pharmacy::searchCure(string nameOfCure)
{
	int iterator = 0;
	if (!accessCure_.empty()) {
		for (Cure i : accessCure_)
		{
			iterator++;
			if (i.getNameOfCure() == nameOfCure)
			{
				auto pointer = accessCure_.cbegin();
				accessCure_.erase(pointer + (iterator - 1));
				neededCure_.push_back(i);
				check_.setListOfPurchasedMedicine(i);
			}
		}
	}
}

Cure Pharmacy::searchAlternative(Cure drug)
{
	for (Cure i : accessCure_)
	{
		if (i.getScopeOfApplication() == drug.getScopeOfApplication() && i.getPriceOfCure() < drug.getPriceOfCure())
			drug = i;
	}
	return drug;
}

void Pharmacy::unloadingOfCure(Cure drug)
{
	int iterator = 0;
	accessCure_.push_back(drug);
	if (!neededCure_.empty()) 
	{
		for (Cure i : neededCure_)
			while (i.getNameOfCure() != drug.getNameOfCure()) iterator++;
		auto pointer = neededCure_.cbegin();
		neededCure_.erase(pointer + iterator);
	}
}

Cure Pharmacy::orderCure()
{
	if (needMoreCure()) 
	{
		Cure drug = neededCure_.back();
		neededCure_.pop_back();
		return drug;
	}
	
}

void Pharmacy::checkForExpirationDate(Date today)
{
	int iterator = 0;
	auto pointer = accessCure_.cbegin();
	for (Cure i : accessCure_)
	{
		if ((i.getExpirationDate().getYear() < today.getYear()) ||
			((i.getExpirationDate().getYear() == today.getYear()) && i.getExpirationDate().getMonth() < today.getMonth()))
		{
			accessCure_.erase(pointer + iterator);
			pointer = accessCure_.cbegin();
			neededCure_.push_back(i);
		}
		else iterator++;
	}
}

CashierOffice Pharmacy::getCheck()
{
	return check_;
}

Cure Pharmacy::getAccessCure()
{
	for(Cure i : accessCure_)
		return i;
}

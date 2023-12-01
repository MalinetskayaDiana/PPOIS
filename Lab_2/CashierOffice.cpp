#include "CashierOffice.h"

void CashierOffice::cureDiscount(float discount)
{
	for (Cure i : listOfPurchasedMedicine_)
		i.setCurePrice((1 - discount) * i.getPriceOfCure());
}

bool CashierOffice::checkIsEmpty()
{
	if (listOfPurchasedMedicine_.empty()) return 1;
	else return 0;
}

int CashierOffice::getTotalPrice()
{
	return totalPrice_;
}

void CashierOffice::setListOfPurchasedMedicine(Cure drug)
{
	listOfPurchasedMedicine_.push_back(drug);
}

Cure CashierOffice::returnCure()
{
	Cure drug = listOfPurchasedMedicine_.back();
	listOfPurchasedMedicine_.pop_back();
	return drug;
}

int CashierOffice::totalPriceCalculation(float discount)
{
	cureDiscount(discount);
	if (listOfPurchasedMedicine_.empty())
		totalPrice_ = 0;
	else
	{
		for (Cure i : listOfPurchasedMedicine_)
		{
			cout << i.getNameOfCure() << "\t" << i.getPriceOfCure() << endl;
			totalPrice_ += i.getPriceOfCure();
		}
	}
	return totalPrice_;
}

int CashierOffice::changeCalculation(int payment, float discount)
{
	int totalPrice = totalPriceCalculation(discount);
	return payment - totalPrice;
}
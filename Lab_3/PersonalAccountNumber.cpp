#include "PersonalAccountNumber.h"

string PersonalAccountNumber::createPersonalAccountNumber()
{
	const string possibleSignificance = "0123456789";
	static string accountNumber;
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(0, possibleSignificance.size() - 1);

	accountNumber.reserve(20);

	for (int i = 0; i < 20; ++i) {
		accountNumber.push_back(possibleSignificance[distribution(generator)]);
	}

	return accountNumber;
}

void PersonalAccountNumber::setNumberOfPersonalAccount()
{
	numberOfPersonalAccount_ = createPersonalAccountNumber();
}

void PersonalAccountNumber::setCash(int money)
{
	cash_ += money;
}

string PersonalAccountNumber::getAccountNumber()
{
	return numberOfPersonalAccount_;
}

int PersonalAccountNumber::getCash()
{
	return cash_;
}

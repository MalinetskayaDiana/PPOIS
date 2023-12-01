#pragma once
#include <string>

using namespace std;

class ActiveIngredient
{
private:
	string nameOfIngredient_;
	int massOfIngredient_;
	int priceOfIngredient_;

public:
	ActiveIngredient();
	ActiveIngredient(string ingredient, int mass, int price);

	string getIngredientName();
	int getIngredientMass();
	int getIngredientPrice();
};


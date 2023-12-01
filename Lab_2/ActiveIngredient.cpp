#include "ActiveIngredient.h"

ActiveIngredient::ActiveIngredient(){}
ActiveIngredient::ActiveIngredient(string ingredient, int mass, int price): nameOfIngredient_(ingredient), massOfIngredient_(mass), priceOfIngredient_(price) {}

string ActiveIngredient::getIngredientName()
{
	return nameOfIngredient_;
}

int ActiveIngredient::getIngredientMass()
{
	return massOfIngredient_;
}

int ActiveIngredient::getIngredientPrice()
{
	return priceOfIngredient_;
}
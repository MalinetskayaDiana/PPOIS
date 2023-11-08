#include "BigInt.h"

string BigInt::negToPos(string number)
{
	if (isNegative(number))
		number.erase(0, 1);
	return number;
}

string BigInt::posToNeg(string number)
{
	if (!isNegative(number))
		number.insert(0, 1, '-');
	return number;
}

bool BigInt::isNegative(string number)
{
	return number[0] == '-';
}

bool BigInt::checkNum(string number)
{
	regex str("^((-[1-9]|[1-9])[0-9]*)|0$");
	return regex_match(number, str);
}

string BigInt::summationSymbols(string summand1, string summand2)
{
	string summaStr, symb;
	int sum, digit1, digit2, digitSum, trans = 0;
	for (int i = summand1.size() - 1; i >= 0; i--)
	{
		digit1 = static_cast<int>(summand1[i]) - '0';
		digit2 = static_cast<int>(summand2[i]) - '0';
		sum = digit1 + digit2 + trans;
		trans = 0;
		if (sum > 9) trans++;
		digitSum = sum % 10;
		symb = static_cast<char>(digitSum) + '0';
		summaStr.insert(0, symb);
	}
	if (trans > 0)
	{
		symb = static_cast<char>(trans) + '0';
		summaStr.insert(0, symb);
	}
	return summaStr;
}

string BigInt::SubtractionSymbols(string reducible, string subtractive)
{
	string symb, diff;
	int digit1, digit2, diffDigit, trans = 0;
	for (int i = reducible.size() - 1; i >= 0; i--)
	{
		digit1 = static_cast<int>(reducible[i]) - '0' - trans;
		digit2 = static_cast<int>(subtractive[i]) - '0';
		trans = 0;
		if (digit1 < digit2)
		{
			digit1 += 10;
			trans++;
		}
		diffDigit = digit1 - digit2;
		symb = static_cast<char>(diffDigit) + '0';
		diff.insert(0, symb);
	}
	int j = 0;
	while (diff[j] == '0' && diff.size() > 1)
		diff.erase(0, 1);
	return diff;
}

void BigInt::multiplicationSymbols(BigInt& result, string num1, string num2)
{
	BigInt Interim_calculation;
	string mult, symb, countOfZero;
	int digit1, digit2, digitMult, trans;
	result.setNum("0");
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		trans = 0;
		for (int j = num2.size() - 1; j >= 0; j--)
		{
			digit1 = static_cast<int>(num1[i]) - '0';
			digit2 = static_cast<int>(num2[j]) - '0';
			digitMult = digit1 * digit2 + trans;
			trans = 0;
			if (digitMult > 9)
			{
				trans = digitMult / 10;
				digitMult %= 10;
			}
			symb = static_cast<char>(digitMult) + '0';
			mult.insert(0, symb);
		}
		if (trans > 0)
		{
			symb = static_cast<char>(trans) + '0';
			mult.insert(0, symb);
		}
		Interim_calculation.setNum(mult);
		result += Interim_calculation;
		countOfZero.insert(0, 1, '0');
		mult = "";
		mult.insert(0, countOfZero);
	}
}

string BigInt::divisionSymbols(BigInt& divisible, BigInt& divider, string num1)
{
	string symb, divide = "";
	int position = divider.num_.size() - 1, digit = 0;
	while (num1.size() >= divider.num_.size() && divisible >= divider)
	{
		divisible.setNum(num1.substr(0, divider.num_.size()));
		position = divisible.num_.size() - 1;
		if (divisible < divider && divisible.num_ != num1)
		{
			divisible.num_.insert(divisible.num_.size(), num1.substr(position + 1, 1));
			position++;
		}
		num1.erase(0, divisible.num_.size());
		position -= divisible.num_.size() - 1;
		while (divisible - divider >= 0)
		{
			divisible -= divider;
			digit++;
		}
		symb = static_cast<char>(digit) + '0';
		digit = 0;
		divide.insert(divide.size(), symb);
		num1.insert(0, divisible.num_);
		divisible.setNum(num1);
	}
	return divide;
}

bool BigInt::moreThan(string num1, string num2)
{
	bool bigger;
	if (num1.size() > num2.size()) bigger = true;
	else if (num1.size() < num2.size())	bigger = false;
	else bigger = num1 > num2;
	return bigger;
}

bool BigInt::lessThan(string num1, string num2)
{
	bool less;
	if (num1.size() < num2.size()) less = true;
	else if (num1.size() > num2.size())	less = false;
	else less = num1 < num2;
	return less;
}

void BigInt::setNum(string number)
{
	try 
	{
		if (!checkNum(number))
		{
			throw invalid_argument("Invalid number format");
		}
		num_ = number;
		signMinus_ = isNegative(number);
	}
	catch (const invalid_argument& error) 
	{
		cout << error.what() << endl;
	}
}

string BigInt::getNum()
{
	return num_;
}

int BigInt::TransformBigInt()
{
	try
	{
		int integer = stoi(num_);
		return integer;
	}
	catch (const out_of_range& error)
	{
		cout << error.what() << endl;
	}
}

BigInt BigInt::operator+(BigInt& bigint)
{
	BigInt result;
	string summa, operand1, operand2;
	if (signMinus_ == bigint.signMinus_)
	{
		operand1 = negToPos(num_);
		operand2 = negToPos(bigint.num_);
		if (operand1.size() > operand2.size())
			operand2.insert(0, operand1.size() - operand2.size(), '0');
		else
			operand1.insert(0, operand2.size() - operand1.size(), '0');
		summa = summationSymbols(operand1, operand2);
		if (signMinus_)
			summa.insert(0, 1, '-');
		result.setNum(summa);
	}
	else
	{
		BigInt summand1, summand2;
		summand1.setNum(negToPos(num_));
		summand2.setNum(negToPos(bigint.num_));
		result = summand1 - summand2;
	}
	return result;
}

BigInt BigInt::operator+=(BigInt& bigint)
{
	*this = *this + bigint;
	return *this;
}

BigInt BigInt::operator+(int integer)
{
	BigInt summand2;
	summand2.setNum(to_string(integer));
	return *this + summand2;
}

BigInt BigInt::operator+=(int integer)
{
	BigInt summand2;
	summand2.setNum(to_string(integer));
	*this = *this + summand2;
	return *this;
}

BigInt BigInt::operator-(BigInt& bigint)
{
	BigInt result;
	string operand1 = num_, operand2 = bigint.num_, diff;
	bool check, isChange = false;
	if (signMinus_ == bigint.signMinus_)
	{
		operand1 = negToPos(num_);
		operand2 = negToPos(bigint.num_);
		if ((*this < bigint && !signMinus_) || (*this > bigint && signMinus_))
		{
			result = bigint - *this;
			isChange = true;
		}
		else
		{
			if (operand1.size() > operand2.size())
				operand2.insert(0, operand1.size() - operand2.size(), '0');
			diff = SubtractionSymbols(operand1, operand2);
			result.setNum(diff);
		}
		if (*this < bigint)
		{
			result.num_.insert(0, 1, '-');
			result.signMinus_ = true;
		}
		if (signMinus_ && isChange && *this > bigint)
			result.num_.erase(0, 1);
	}
	else
	{
		BigInt reducible, subtractive;
		reducible.setNum(num_);
		if (signMinus_)
			subtractive.setNum(posToNeg(bigint.num_));
		else
			subtractive.setNum(negToPos(bigint.num_));
		result = reducible + subtractive;
	}
	return result;
}

BigInt BigInt::operator-=(BigInt& bigint)
{
	*this = *this - bigint;
	return *this;
}

BigInt BigInt::operator-(int integer)
{
	BigInt subtractive;
	subtractive.setNum(to_string(integer));
	return *this - subtractive;
}

BigInt BigInt::operator-=(int integer)
{
	BigInt subtractive;
	subtractive.setNum(to_string(integer));
	*this = *this - subtractive;
	return *this;
}

BigInt BigInt::operator*(BigInt& bigint)
{
	BigInt result;
	string operand1, operand2;
	int sizeNum1, sizeNum2;
	sizeNum1 = num_.size();
	sizeNum2 = bigint.num_.size();
	if (signMinus_)	sizeNum1--;
	else sizeNum2--;
	if (sizeNum1 < sizeNum2)
	{
		operand1 = negToPos(bigint.num_);
		operand2 = negToPos(num_);
	}
	else
	{
		operand1 = negToPos(num_);
		operand2 = negToPos(bigint.num_);
	}
	multiplicationSymbols(result, operand1, operand2);
	if ((signMinus_ && !bigint.signMinus_) || (!signMinus_ && bigint.signMinus_))
	{
		result.num_.insert(0, 1, '-');
		result.signMinus_ = true;
	}
	return result;
}

BigInt BigInt::operator*=(BigInt& bigint)
{
	*this = *this * bigint;
	return *this;
}

BigInt BigInt::operator*(int integer)
{
	BigInt multiplier;
	multiplier.setNum(to_string(integer));
	return *this * multiplier;
}

BigInt BigInt::operator*=(int integer)
{
	BigInt multiplier;
	multiplier.setNum(to_string(integer));
	*this = *this * multiplier;
	return *this;
}

BigInt BigInt::operator/(BigInt& bigint)
{
	BigInt divisible, divider, result;
	string operand1, operand2, divide = "";
	operand1 = negToPos(num_);
	operand2 = negToPos(bigint.num_);
	divisible.setNum(operand1);
	divider.setNum(operand2);
	if (divisible < divider)
		result.setNum("0");
	else
	{
		divide = divisionSymbols(divisible, divider, operand1);
		result.setNum(divide);
	}
	if (((signMinus_ && !bigint.signMinus_) || (!signMinus_ && bigint.signMinus_)) && result.num_ != "0")
	{
		result.num_.insert(0, 1, '-');
		result.signMinus_ = true;
	}
	return result;
}

BigInt BigInt::operator/=(BigInt& bigint)
{
	*this = *this / bigint;
	return *this;
}

BigInt BigInt::operator/(int integer)
{
	BigInt divider;
	divider.setNum(to_string(integer));
	return *this / divider;
}

BigInt BigInt::operator/=(int integer)
{
	BigInt divider;
	divider.setNum(to_string(integer));
	*this = *this / divider;
	return *this;
}

BigInt BigInt::operator++()
{
	BigInt result;
	result = *this + 1;
	return result;
}

BigInt BigInt::operator++(int)
{
	BigInt result = *this;
	*this = *this + 1;
	return result;
}

BigInt BigInt::operator--()
{
	BigInt result;
	result = *this - 1;
	return result;
}

BigInt BigInt::operator--(int)
{
	BigInt result = *this;
	*this = *this - 1;
	return result;
}

bool BigInt::operator>(BigInt& bigint)
{
	bool bigger;
	string operand1 = num_, operand2 = bigint.num_;
	if (signMinus_ == bigint.signMinus_)
	{
		operand1 = negToPos(num_);
		operand2 = negToPos(bigint.num_);
		bigger = moreThan(operand1, operand2);
		if (signMinus_ && operand1 != operand2)	bigger = !bigger;
	}
	else
	{
		if (signMinus_)	bigger = false;
		else bigger = true;
	}
	return bigger;
}

bool BigInt::operator<(BigInt& bigint)
{
	bool less;
	string operand1 = num_, operand2 = bigint.num_;
	if (signMinus_ == bigint.signMinus_)
	{
		operand1 = negToPos(num_);
		operand2 = negToPos(bigint.num_);
		less = lessThan(operand1, operand2);
		if (signMinus_ && operand1 != operand2) less = !less;
	}
	else
	{
		if (signMinus_)	less = true;
		else less = false;
	}
	return less;
}

bool BigInt::operator>=(BigInt& bigint)
{
	if (!(*this < bigint))
		return true;
	else
		return false;
}

bool BigInt::operator<=(BigInt& bigint)
{
	if (!(*this > bigint))
		return true;
	else
		return false;
}

bool BigInt::operator>(int integer)
{
	BigInt operend2;
	operend2.setNum(to_string(integer));
	if (*this > operend2)
		return true;
	else
		return false;
}

bool BigInt::operator<(int integer)
{
	BigInt operend2;
	operend2.setNum(to_string(integer));
	if (*this < operend2)
		return true;
	else
		return false;
}

bool BigInt::operator>=(int integer)
{
	BigInt operend2;
	operend2.setNum(to_string(integer));
	if (*this >= operend2)
		return true;
	else
		return false;
}

bool BigInt::operator<=(int integer)
{
	BigInt operend2;
	operend2.setNum(to_string(integer));
	if (*this <= operend2)
		return true;
	else
		return false;
}
#pragma once
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class BigInt
{
private:

	bool signMinus_;
	string num_;

	string negToPos(string number);
	string posToNeg(string number);
	bool isNegative(string number);
	bool checkNum(string number);
	string summationSymbols(string num1, string num2);
	string SubtractionSymbols(string num1, string num2);
	void multiplicationSymbols(BigInt& D, string num1, string num2);
	string divisionSymbols(BigInt& A, BigInt& B, string num1);
	bool moreThan(string num1, string num2);
	bool lessThan(string num1, string num2);

public:

	void setNum(string number);
	string getNum();
	int TransformBigInt();

	BigInt operator+(BigInt& bigint);
	BigInt operator+=(BigInt& bigint);
	BigInt operator+(int integer);
	BigInt operator+=(int integer);

	BigInt operator-(BigInt& bigint);
	BigInt operator-=(BigInt& bigint);
	BigInt operator-(int integer);
	BigInt operator-=(int integer);

	BigInt operator*(BigInt& bigint);
	BigInt operator*=(BigInt& bigint);
	BigInt operator*(int integer);
	BigInt operator*=(int integer);

	BigInt operator/(BigInt& bigint);
	BigInt operator/=(BigInt& bigint);
	BigInt operator/(int integer);
	BigInt operator/=(int integer);

	BigInt operator++();
	BigInt operator++(int);

	BigInt operator--();
	BigInt operator--(int);

	bool operator>(BigInt& bigint);
	bool operator<(BigInt& bigint);
	bool operator>=(BigInt& bigint);
	bool operator<=(BigInt& bigint);

	bool operator>(int integer);
	bool operator<(int integer);
	bool operator>=(int integer);
	bool operator<=(int integer);
};

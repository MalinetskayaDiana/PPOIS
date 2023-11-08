#include "pch.h"
#include "CppUnitTest.h"
#include "..\PPOIS_lab1\BigInt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BigIntTests
{
	TEST_CLASS(BigIntTests)
	{
	public:
		TEST_METHOD(TransformToInt_Success_Test)
		{
			BigInt A;
			A.setNum("99999999");
			int a = A.TransformBigInt(), result = 99999999;
			Assert::AreEqual(result, a);
		}
		TEST_METHOD(Summa_BigInts_Pos_Test)
		{
			BigInt A, B, C;
			A.setNum("999999999999");
			B.setNum("23456");
			C = A + B;
			string result = "1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Summa_BigInts_Neg_Test)
		{
			BigInt A, B, C;
			A.setNum("-999999999999");
			B.setNum("-23456");
			C = A + B;
			string result = "-1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Summa_BigInts_PosAndNeg_Test)
		{
			BigInt A, B, C;
			A.setNum("999999999999");
			B.setNum("-23456");
			C = A + B;
			string result = "999999976543";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Summa_BigInts_NegAndPos_Test)
		{
			BigInt A, B, C;
			A.setNum("23456");
			B.setNum("999999999999");
			C = A + B;
			string result = "1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Add_BigInt_Pos_Test)
		{
			BigInt A, B;
			A.setNum("999999999999");
			B.setNum("23456");
			A += B;
			string result = "1000000023455";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Summa_BigIntAndInt_Pos_Test)
		{
			BigInt A, C;
			A.setNum("999999999999");
			int b = 23456;
			C = A + b;
			string result = "1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Add_Int_Pos_Test)
		{
			BigInt A, B;
			A.setNum("999999999999");
			int b = 23456;
			A += b;
			string result = "1000000023455";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Minus_BigInts_Neg_Test)
		{
			BigInt A, B, C;
			A.setNum("-23456");
			B.setNum("-999999999999");
			C = A - B;
			string result = "999999976543";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Minus_BigInts_PosAndNeg_Test)
		{
			BigInt A, B, C;
			A.setNum("999999999999");
			B.setNum("-23456");
			C = A - B;
			string result = "1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Minus_BigInts_NegAndPos_Test)
		{
			BigInt A, B, C;
			A.setNum("-999999999999");
			B.setNum("23456");
			C = A - B;
			string result = "-1000000023455";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Delete_BigInt_Pos_Test)
		{
			BigInt A, B;
			A.setNum("999999999999");
			B.setNum("23456");
			A -= B;
			string result = "999999976543";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Minus_BigIntAndInt_Pos_Test)
		{
			BigInt A, C;
			A.setNum("999999999999");
			int b = 23456;
			C = A - b;
			string result = "999999976543";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Delete_Int_Pos_Test)
		{
			BigInt A, B;
			A.setNum("999999999999");
			int b = 23456;
			A -= b;
			string result = "999999976543";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Multiplication_BigInts_Pos_Test)
		{
			BigInt A, B, C;
			A.setNum("3333");
			B.setNum("23456");
			C = A * B;
			string result = "78178848";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Multiplication_BigInts_PosAndNeg_Test)
		{
			BigInt A, B, C;
			A.setNum("3333");
			B.setNum("-23456");
			C = A * B;
			string result = "-78178848";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(MultiplicationAdd_BigInts_Pos_Test)
		{
			BigInt A, B;
			A.setNum("3333");
			B.setNum("23456");
			A *= B;
			string result = "78178848";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Multiplication_BigIntsAndInt_Pos_Test)
		{
			BigInt A, C;
			A.setNum("3333");
			int b = 23456;
			C = A * b;
			string result = "78178848";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(MultiplicationAdd_Int_Pos_Test)
		{
			BigInt A, B;
			A.setNum("3333");
			int b=23456;
			A *= b;
			string result = "78178848";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(DevidingByMore_BigInts_Pos_Test)
		{
			BigInt A, B, C;
			A.setNum("3333");
			B.setNum("23456");
			C = A / B;
			string result = "0";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(DevidingByLess_BigInts_Pos_Test)
		{
			BigInt A, B, C;
			A.setNum("23456");
			B.setNum("3333");
			C = A / B;
			string result = "7";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(DevidingByLess_BigInts_PosAndNeg_Test)
		{
			BigInt A, B, C;
			A.setNum("-23456");
			B.setNum("3333");
			C = A / B;
			string result = "-7";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(DevidingByLessDelete_BigInts_Pos_Test)
		{
			BigInt A, B;
			A.setNum("23456");
			B.setNum("3333");
			A /= B;
			string result = "7";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(DevidingByLess_BigIntsAndInt_Pos_Test)
		{
			BigInt A, C;
			A.setNum("23456");
			int b = 3333;
			C = A / b;
			string result = "7";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(DevidingByLessDelete_Int_Pos_Test)
		{
			BigInt A, B;
			A.setNum("23456");
			int b = 3333;
			A /= b;
			string result = "7";
			Assert::AreEqual(A.getNum(), result);
		}
		TEST_METHOD(Preincrement_Test)
		{
			BigInt A, C;
			A.setNum("999999999999");
			C = ++A;
			string result = "1000000000000";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Postincrement_Test)
		{
			BigInt A, C;
			A.setNum("999999999999");
			C = A++;
			string result = "999999999999";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Predecrement_Test)
		{
			BigInt A, C;
			A.setNum("1000000000000");
			C = --A;
			string result = "999999999999";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(Postdecrement_Test)
		{
			BigInt A, C;
			A.setNum("1000000000000");
			C = A--;
			string result = "1000000000000";
			Assert::AreEqual(C.getNum(), result);
		}
		TEST_METHOD(BigIntMoreBigInt_NegAndPos_Test)
		{
			BigInt A, B;
			A.setNum("-1000000000000");
			B.setNum("1000000000000");
			bool isBigger = A > B, result = false;
			Assert::AreEqual(isBigger, result);
		}
		TEST_METHOD(BigIntMoreBigInt_PosAndNeg_Test)
		{
			BigInt A, B;
			A.setNum("1000000000000");
			B.setNum("-1000000000000");
			bool isBigger = A > B, result = true;
			Assert::AreEqual(isBigger, result);
		}
		TEST_METHOD(BigIntLessBigInt_PosAndNeg_Test)
		{
			BigInt A, B;
			A.setNum("1000000000000");
			B.setNum("-1000000000000");
			bool isLess = A < B, result = false;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntLessOrEqualBigInt_PosAndNeg_Test)
		{
			BigInt A, B;
			A.setNum("1000000000000");
			B.setNum("-1000000000000");
			bool isLess = A <= B, result = false;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntLessOrEqualBigInt_NegAndPos_Test)
		{
			BigInt A, B;
			A.setNum("-1000000000000");
			B.setNum("1000000000000");
			bool isLess = A <= B, result = true;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntMoreInt_PosAndNeg_Test)
		{
			BigInt A;
			A.setNum("1000000000000");
			int b = -1000000000000;
			bool isBigger = A > b, result = true;
			Assert::AreEqual(isBigger, result);
		}
		TEST_METHOD(BigIntMoreInt_NegAndPos_Test)
		{
			BigInt A;
			A.setNum("-1000000000000");
			int b = 1000000000000;
			bool isBigger = A > b, result = false;
			Assert::AreEqual(isBigger, result);
		}
		TEST_METHOD(BigIntLessInt_PosAndNeg_Test)
		{
			BigInt A;
			A.setNum("1000000000000");
			int b = -1000000000000;
			bool isLess = A < b, result = false;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntLessInt_NegAndPos_Test)
		{
			BigInt A;
			A.setNum("-1000000000000");
			int b = 1000000000000;
			bool isLess = A < b, result = true;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntLessOrEqualInt_PosAndNeg_Test)
		{
			BigInt A;
			A.setNum("1000000000000");
			int b = -1000000000000;
			bool isLess = A <= b, result = false;
			Assert::AreEqual(isLess, result);
		}
		TEST_METHOD(BigIntLessOrEqualInt_NegAndPos_Test)
		{
			BigInt A;
			A.setNum("-1000000000000");
			int b = 1000000000000;
			bool isLess = A <= b, result = true;
			Assert::AreEqual(isLess, result);
		}
	};
}

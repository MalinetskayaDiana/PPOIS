#include "pch.h"
#include "CppUnitTest.h"
#include "../Medicine_Lab2/InfoExchange.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MedicineTest
{
	TEST_CLASS(MedicineTest)
	{
	public:
		
		TEST_METHOD(checkIsEmptyTrueTest)
		{
			CashierOffice check;
			bool isEmpty = check.checkIsEmpty(), result = true;
			Assert::AreEqual(isEmpty, result);
		}
		TEST_METHOD(checkIsEmptyFalseTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			polaris.supplyOfMedicine(newCure, pharmacy);
			pharmacy.searchCure("Vitamin D3");
			bool isEmpty = pharmacy.getCheck().checkIsEmpty(), result = false;
			Assert::AreEqual(isEmpty, result);
		}
		TEST_METHOD(returnCureTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			polaris.supplyOfMedicine(newCure, pharmacy);
			pharmacy.searchCure("Vitamin D3");
			Cure returnedCure = pharmacy.getCheck().returnCure();
			string resultName = "Vitamin D3", scope = "Dietary supplement", resultIngridient = "D3";
			int resultPrice = 2100, todayMonth = 12, todayYear = 2023, futureYear = 2025;
			Assert::AreEqual(newCure.getNameOfCure(), resultName);
			Assert::AreEqual(newCure.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(newCure.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(newCure.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(newCure.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(newCure.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(newCure.getScopeOfApplication(), scope);
			Assert::AreEqual(newCure.getPriceOfCure(), resultPrice);
		}
		TEST_METHOD(totalPriceCalculationTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			polaris.supplyOfMedicine(newCure, pharmacy);
			pharmacy.searchCure("Vitamin D3");
			int totalPrice = pharmacy.getCheck().totalPriceCalculation(1), result = 2100;
			Assert::AreEqual(totalPrice, result);
		}
		TEST_METHOD(ChangeCalculationTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			polaris.supplyOfMedicine(newCure, pharmacy);
			pharmacy.searchCure("Vitamin D3");
			int totalPrice = pharmacy.getCheck().totalPriceCalculation(1), change = pharmacy.getCheck().changeCalculation(2500, 1), result = 400;
			Assert::AreEqual(change, result);
		}
		TEST_METHOD(getTotalPriceTest)
		{
			CashierOffice check;
			int totalPrice = check.getTotalPrice(), result = 0;
			Assert::AreEqual(totalPrice, result);
		}

		TEST_METHOD(AskSymptomsTest)
		{
			Doctor asher("Asher");
			asher.setPatientSymptoms("runny nose");
			string result = "runny nose";
			Assert::AreEqual(asher.getPatientSymptoms(), result);
		}
		TEST_METHOD(AskKnowledgeOfCureTest)
		{
			Doctor asher("Asher");
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			Cure cure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement", 100);
			asher.setNewDrug(cure);
			Cure knownCure = asher.getknowledgeOfCure();
			string resultName = "Vitamin D3", resultIngridient = "D3", scope = "Dietary supplement";
			int todayMonth = 12, todayYear = 2023, futureYear = 2025, resultPrice = 100;
			Assert::AreEqual(knownCure.getNameOfCure(), resultName);
			Assert::AreEqual(knownCure.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(knownCure.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(knownCure.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(knownCure.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(knownCure.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(knownCure.getScopeOfApplication(), scope);
			Assert::AreEqual(knownCure.getPriceOfCure(), resultPrice);
		}
		TEST_METHOD(PrescribeTest)
		{
			Doctor asher("Asher");
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			Cure cure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement", 100);
			asher.setNewDrug(cure);
			asher.setPatientSymptoms("Dietary supplement");
			Cure prescribeCure = asher.prescribeDrugs();
			string resultName = "Vitamin D3", resultIngridient = "D3", scope = "Dietary supplement";
			int todayMonth = 12, todayYear = 2023, futureYear = 2025, resultPrice = 100;
			Assert::AreEqual(prescribeCure.getNameOfCure(), resultName);
			Assert::AreEqual(prescribeCure.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(prescribeCure.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(prescribeCure.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(prescribeCure.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(prescribeCure.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(prescribeCure.getScopeOfApplication(), scope);
			Assert::AreEqual(prescribeCure.getPriceOfCure(), resultPrice);
		}
		TEST_METHOD(SetDoseTest)
		{
			Doctor asher("Asher");
			int dose = asher.giveDose(85, 10), result = 850;
			Assert::AreEqual(dose, result);
		}
		TEST_METHOD(SetListOfManucaturerTest)
		{
			InfoExchange company;
			Manufacturer polaris("Polaris", "Russia", 20);
			company.setListOfManucaturer(polaris);
			string name = "Polaris", country = "Russia";
			int percent = 20;
			Assert::AreEqual(company.getListOfManucaturer().getNameOfManufacturer(), name);
			Assert::AreEqual(company.getListOfManucaturer().getCountryOfManufacturer(), country);
			Assert::AreEqual(company.getListOfManucaturer().getPercentageOfManufacturer(), percent);
		}
		TEST_METHOD(SetListOfDoctorsTest)
		{
			InfoExchange company;
			Doctor asher("Asher");
			company.setNewDoctor(asher);
			string doctorName = "Asher";
			Assert::AreEqual(company.getDoctor().getName(), doctorName);
		}
		TEST_METHOD(CreateNewCureTest)
		{
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			string resultName = "Vitamin D3", scope = "Dietary supplement", resultIngridient = "D3";
			int resultPrice = 2100, todayMonth = 12, todayYear = 2023, futureYear = 2025;
			Assert::AreEqual(newCure.getNameOfCure(), resultName);
			Assert::AreEqual(newCure.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(newCure.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(newCure.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(newCure.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(newCure.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(newCure.getScopeOfApplication(), scope);
			Assert::AreEqual(newCure.getPriceOfCure(), resultPrice);
		}
		TEST_METHOD(QualityCheckTrueTest)
		{
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			bool isCompliat = polaris.complianceQuality(newCure, 53), result = true;
			Assert::AreEqual(isCompliat, result);
		}
		TEST_METHOD(QualityCheckFalseTest)
		{
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 83, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			bool isCompliat = polaris.complianceQuality(newCure, 53), result = false;
			Assert::AreEqual(isCompliat, result);
		}
		TEST_METHOD(ProducedThisCureTrueTest)
		{
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			bool isProduced = polaris.isProduceCure(newCure), result = true;
			Assert::AreEqual(isProduced, result);
		}
		TEST_METHOD(supplyOfMedicineTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure newCure = polaris.getCure("Vitamin D3");
			string resultName = "Vitamin D3", scope = "Dietary supplement", resultIngridient = "D3";
			int resultPrice = 2100, todayMonth = 12, todayYear = 2023, futureYear = 2025;
			polaris.supplyOfMedicine(newCure, pharmacy);
			Cure cureInPharmacy = pharmacy.getAccessCure();
			Assert::AreEqual(cureInPharmacy.getNameOfCure(), resultName);
			Assert::AreEqual(cureInPharmacy.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(cureInPharmacy.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(cureInPharmacy.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(cureInPharmacy.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(cureInPharmacy.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(cureInPharmacy.getScopeOfApplication(), scope);
			Assert::AreEqual(cureInPharmacy.getPriceOfCure(), resultPrice);
		}
		TEST_METHOD(ConstractionPatient)
		{
			Patient bob("Bob", 35, 85, 1, 10000);
			string name = "Bob", symptom = "runny nose";
			int age = 35, weight = 85, money = 10000;
			float discount = 1;
			bob.setSymptoms("runny nose");
			Assert::AreEqual(bob.getName(), name);
			Assert::AreEqual(bob.getAge(), age);
			Assert::AreEqual(bob.getWeight(), weight);
			Assert::AreEqual(bob.getDiscount(), discount);
			Assert::AreEqual(bob.payForCure(), money);
		}
		TEST_METHOD(searchAlternaticeTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			ActiveIngredient vitaminB12("B12", 40, 80);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			polaris.createNewCure("Vitamin B12", today, endOfCure, vitaminB12, "Dietary supplement");
			Cure cureExpancive = polaris.getCure("Vitamin D3");
			Cure cureCheap = polaris.getCure("Vitamin B12");
			polaris.supplyOfMedicine(cureExpancive, pharmacy);
			polaris.supplyOfMedicine(cureCheap, pharmacy);
			Cure cureMoreCheap = pharmacy.searchAlternative(cureExpancive);
			string resultName = "Vitamin B12", resultIngridient = "B12", scope = "Dietary supplement";
			int resultPrice = 1680, todayMonth = 12, todayYear = 2023, futureYear = 2025;
			Assert::AreEqual(cureMoreCheap.getNameOfCure(), resultName);
			Assert::AreEqual(cureMoreCheap.getDateOfProduction().getMonth(), todayMonth);
			Assert::AreEqual(cureMoreCheap.getDateOfProduction().getYear(), todayYear);
			Assert::AreEqual(cureMoreCheap.getExpirationDate().getMonth(), todayMonth);
			Assert::AreEqual(cureMoreCheap.getExpirationDate().getYear(), futureYear);
			Assert::AreEqual(cureMoreCheap.getIngredirnt().getIngredientName(), resultIngridient);
			Assert::AreEqual(cureMoreCheap.getScopeOfApplication(), scope);
			Assert::AreEqual(cureMoreCheap.getPriceOfCure(), resultPrice);
		}
		/*TEST_METHOD(CureSaleTrueTest)
		{
			Pharmacy pharmacy;
			Patient bob("Bob", 35, 85, 1, 10000);
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure;
			ActiveIngredient vitaminD3("D3", 53, 100);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure cureForBob = polaris.getCure("Vitamin D3");
			bob.setListOfNeededCure(cureForBob);
			pharmacy.getCheck().setListOfPurchasedMedicine(cureForBob);
			pharmacy.cureSale(bob);
			int bobMoney = bob.payForCure(), result = 7900;
			Assert::AreEqual(bobMoney, result);
		}*/
		TEST_METHOD(checkForExpirationDateTrueTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure, checkDate;
			ActiveIngredient vitaminD3("D3", 53, 100);
			ActiveIngredient vitaminB12("B12", 40, 80);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			checkDate.setDate(2, 2026);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			polaris.createNewCure("Vitamin B12", today, endOfCure, vitaminB12, "Dietary supplement");
			Cure cureExpancive = polaris.getCure("Vitamin D3");
			Cure cureCheap = polaris.getCure("Vitamin B12");
			polaris.supplyOfMedicine(cureExpancive, pharmacy);
			polaris.supplyOfMedicine(cureCheap, pharmacy);
			pharmacy.checkForExpirationDate(checkDate);
			bool needCure = pharmacy.needMoreCure(), result = true;
			Assert::AreEqual(needCure, result);
		}
		TEST_METHOD(orderCureTrueTest)
		{
			Pharmacy pharmacy;
			Manufacturer polaris("Polaris", "Russia", 20);
			Date today, endOfCure, checkDate;
			ActiveIngredient vitaminD3("D3", 53, 100);
			ActiveIngredient vitaminB12("B12", 40, 80);
			today.setDate(12, 2023);
			endOfCure.setDate(12, 2025);
			checkDate.setDate(2, 2026);
			polaris.createNewCure("Vitamin D3", today, endOfCure, vitaminD3, "Dietary supplement");
			Cure cureExpancive = polaris.getCure("Vitamin D3");
			polaris.supplyOfMedicine(cureExpancive, pharmacy);
			pharmacy.checkForExpirationDate(checkDate);
			pharmacy.orderCure();
			bool needCure = pharmacy.needMoreCure(), result = false;
			Assert::AreEqual(needCure, result);
		}
	};
}

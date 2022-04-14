#include "RepoTests.h"

void RepoTests::runAllTests()
{
	creationTest();
	gettersTest();
	featuresTests();
}

int RepoTests::creationTest()
{
	Expenses expenses = Expenses();

	assert(expenses.getSize() == 28);
	assert(expenses.getCurrentDay() == 0);

	for (int i = 0; i < expenses.getSize(); i++)
	{
		assert(expenses.getAll()[i].getMancare() == 0);
		assert(expenses.getAll()[i].getMenaj() == 0);
		assert(expenses.getAll()[i].getTransport() == 0);
		assert(expenses.getAll()[i].getInternet() == 0);
		assert(expenses.getAll()[i].getHaine() == 0);
	}
	return 0;
}

int RepoTests::gettersTest()
{
	Expenses expenses = Expenses();

	char type[10] = "mancare";
	expenses.addExpense(100, type);

	assert(expenses.getAll()[0].getMancare() == 100);

	return 0;
}

int RepoTests::featuresTests()
{
	Expenses expenses = Expenses();

	char type1[10] = "mancare";
	char type2[10] = "internet";

	// Add tests
	expenses.addExpense(150, type1);
	expenses.addExpense(200, type2);

	assert(expenses.getAll()[expenses.getCurrentDay()].getMancare() == 150);
	assert(expenses.getAll()[expenses.getCurrentDay()].getInternet() == 200);

	// Insert tests
	expenses = Expenses();
	
	expenses.insertExpense(150, 2, type1);
	expenses.insertExpense(200, 3, type2);

	assert(expenses.getAll()[2].getMancare() == 150);
	assert(expenses.getAll()[3].getInternet() == 200);

	// Modify tests

	expenses.elimExpenseByDay(2);
	expenses.elimExpenseByDay(3);

	assert(expenses.getAll()[2].getMancare() == 0);
	assert(expenses.getAll()[3].getInternet() == 0);

	expenses.insertExpense(150, 2, type1);
	expenses.insertExpense(200, 3, type2);

	expenses.elimExpenseFromTo(2, 4);

	assert(expenses.getAll()[2].getMancare() == 0);
	assert(expenses.getAll()[3].getInternet() == 0);

	expenses.insertExpense(150, 2, type1);
	expenses.insertExpense(200, 3, type2);

	expenses.elimExpenseByType(type1);
	expenses.elimExpenseByType(type2);

	assert(expenses.getAll()[2].getMancare() == 0);
	assert(expenses.getAll()[2].getMancare() == 0);
	
	// Listing tests

	expenses.insertExpense(150, 2, type1);
	

	assert(expenses.getTotalFoodExpenses() == 150);
	
	
	// Property tests

	expenses.insertExpense(200, 3, type2);
	expenses.insertExpense(150, 4, type1);

	assert(expenses.getDayMaxExp() == 3);
	assert(expenses.getTotalFoodExpenses() == 300);

	// Filtering tests

	expenses.filterFoodExpenses();
	
	assert(expenses.getAll()[3].getInternet() == 0);
	assert(expenses.getAll()[4].getMancare() == 150);

	expenses.addExpense(300, type1);
	expenses.filterFoodExpensesSmallerThan(200);

	assert(expenses.getAll()[4].getMancare() == 150);
	assert(expenses.getAll()[0].getMancare() == 0);

	// Undo test

	expenses.undo();
	assert(expenses.getAll()[0].getMancare() == 300);

	return 0;
}

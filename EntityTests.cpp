#include "EntityTests.h"

void EntityTests::runAllTests()
{
	creationTest();
	gettersSettersTest();
}

int EntityTests::creationTest()
{
	monthExpense expense1 = monthExpense();

	assert(expense1.getHaine() == 0);
	assert(expense1.getInternet() == 0);
	assert(expense1.getMancare() == 0);
	assert(expense1.getTransport() == 0);
	assert(expense1.getMenaj() == 0);

	return 0;
}

int EntityTests::gettersSettersTest()
{
	monthExpense expense1 = monthExpense();
	assert(expense1.getHaine() == 0);
	assert(expense1.getInternet() == 0);
	assert(expense1.getMancare() == 0);
	assert(expense1.getTransport() == 0);
	assert(expense1.getMenaj() == 0);

	expense1.setHaine(1);
	expense1.setInternet(2);
	expense1.setMancare(3);
	expense1.setMenaj(4);
	expense1.setTransport(5);

	assert(expense1.getHaine() == 1);
	assert(expense1.getInternet() == 2);
	assert(expense1.getMancare() == 3);
	assert(expense1.getMenaj() == 4);
	assert(expense1.getTransport() == 5);

	return 0;
}

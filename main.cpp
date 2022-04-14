#include <iostream>
#include "Expenses.h"
#include "UI.h"
#include "EntityTests.h"
#include "RepoTests.h"

using namespace std;

int main() {
	// Run tests
	EntityTests::runAllTests();
	RepoTests::runAllTests();

	Expenses monthlyExpenses = Expenses();
	UI presentation = UI(monthlyExpenses);

	presentation.run();

	return 0;
}
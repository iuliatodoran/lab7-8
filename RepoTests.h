#pragma once
#include <iostream>
#include <cassert>
#include "Expenses.h"
#include "monthExpense.h"

class RepoTests {
public:
	static void runAllTests();
	static int creationTest();
	static int gettersTest();
	static int featuresTests();
};
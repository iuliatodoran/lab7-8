#pragma once
#include <iostream>
#include <iomanip>
#include "Expenses.h"
#include "monthExpense.h"
#include <string>
using namespace std;

class UI {
public:
	UI();
	UI(const Expenses& other);

	void run();

private:
	Expenses monthlyExpenses;
};
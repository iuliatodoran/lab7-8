#pragma once
#include "monthExpense.h"
#include <iostream>

class Expenses : public monthExpense {
public:
	// Constructors
	Expenses();
	Expenses(const Expenses& other);
	Expenses(int currentDay);

	// Destructor
	~Expenses();

	// Getters
	monthExpense* getAll();
	int getSize();
	int getCurrentDay();

	// Operators
	Expenses& operator=(const Expenses& other);

	void addExpense(int money, char* type);
	void insertExpense(int money, unsigned int day, char* type);

	void elimExpenseByDay(int day);
	void elimExpenseFromTo(int from, int to);
	void elimExpenseByType(char* type);

	int getTotalFoodExpenses();
	int getDayMaxExp();

	void filterFoodExpenses();
	void filterFoodExpensesSmallerThan(int value);

	void undo();

private:
	monthExpense *entities;
	monthExpense *previousForm;
	int currentDay;
	int nrOfEntities;
};
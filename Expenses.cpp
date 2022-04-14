#include "Expenses.h"
#include "monthExpense.h"
#include <iostream>
#include <cstring>
Expenses::Expenses()
{
	nrOfEntities = 28;
	this->currentDay = 0;
	this->entities = new monthExpense[nrOfEntities]{};
	this->previousForm = new monthExpense[nrOfEntities]{};
}

Expenses::Expenses(const Expenses& other)
{
	delete[] entities;
	this->nrOfEntities = other.nrOfEntities;
	this->currentDay = other.currentDay;
	this->entities = new monthExpense[nrOfEntities]{};

	for (int i = 0; i < nrOfEntities; i++)
		entities[i] = other.entities[i];
}

Expenses::Expenses(int currentDay)
{
	*this = Expenses();
	this->currentDay = currentDay;
}

Expenses::~Expenses()
{
	delete[] this->entities;
}

monthExpense* Expenses::getAll()
{
	return entities;
}

int Expenses::getSize()
{
	return this->nrOfEntities;
}

int Expenses::getCurrentDay()
{
	return currentDay;
}

Expenses& Expenses::operator=(const Expenses& other)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	delete[] this->entities;
	this->nrOfEntities = other.nrOfEntities;
	this->entities = new monthExpense[nrOfEntities]{};

	for (int i = 0; i < nrOfEntities; i++) {
		this->entities[i] = other.entities[i];
	}

	return *this;
}

void Expenses::addExpense(int money, char* type) {
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	if (strcmp(type, "menaj") == 0)
		entities[currentDay].setMenaj(entities[currentDay].getMenaj() + money);
	else if (strcmp(type, "mancare") == 0)
		entities[currentDay].setMancare(entities[currentDay].getMancare() + money);
	else if (strcmp(type, "transport") == 0)
		entities[currentDay].setTransport(entities[currentDay].getTransport() + money);
	else if (strcmp(type, "internet") == 0)
		entities[currentDay].setInternet(entities[currentDay].getInternet() + money);
	else if (strcmp(type, "haine") == 0)
		entities[currentDay].setHaine(entities[currentDay].getHaine() + money);
	else
		std::cout << "Invalid type!";
}

void Expenses::insertExpense(int money, unsigned int day, char* type)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	if (strcmp(type, "menaj") == 0)
		entities[day].setMenaj(entities[day].getMenaj() + money);
	else if (strcmp(type, "mancare") == 0)
		entities[day].setMancare(entities[day].getMancare() + money);
	else if (strcmp(type, "transport") == 0)
		entities[day].setTransport(entities[day].getTransport() + money);
	else if (strcmp(type, "internet") == 0)
		entities[day].setInternet(entities[day].getInternet() + money);
	else if (strcmp(type, "haine") == 0)
		entities[day].setHaine(entities[day].getHaine() + money);
	else
		std::cout << "Invalid type!";
}

void Expenses::elimExpenseByDay(int day)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	entities[day].setHaine(0);
	entities[day].setInternet(0);
	entities[day].setMenaj(0);
	entities[day].setMancare(0);
	entities[day].setTransport(0);
}

void Expenses::elimExpenseFromTo(int from, int to)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	for (int i = from; i < to; i++)
	{
		entities[i].setHaine(0);
		entities[i].setInternet(0);
		entities[i].setMenaj(0);
		entities[i].setMancare(0);
		entities[i].setTransport(0);
	}
}

void Expenses::elimExpenseByType(char* type)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	if (strcmp(type, "menaj") == 0) {
		for (int i = 0; i < nrOfEntities; i++)
			entities[i].setMenaj(0);
	}
	else if (strcmp(type, "haine") == 0) {
		for (int i = 0; i < nrOfEntities; i++)
			entities[i].setHaine(0);
	}
	else if (strcmp(type, "internet") == 0) {
		for (int i = 0; i < nrOfEntities; i++)
			entities[i].setInternet(0);
	}
	else if (strcmp(type, "mancare") == 0) {
		for (int i = 0; i < nrOfEntities; i++)
			entities[i].setMancare(0);
	}
	else if (strcmp(type, "transport") == 0) {
		for (int i = 0; i < nrOfEntities; i++)
			entities[i].setTransport(0);
	}
	else
		std::cout << "Invalid type!";
}

int Expenses::getTotalFoodExpenses()
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	int total = 0;
	for (int i = 0; i < nrOfEntities; i++)
		total += entities[i].getMancare();

	return total;
}

int Expenses::getDayMaxExp()
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	int maxExp = 0, maxDay = 0;

	for (int i = 0; i < nrOfEntities; i++) {
		int currentTotal = entities[i].getHaine() + entities[i].getInternet() + entities[i].getMenaj() + entities[i].getMancare() + entities[i].getTransport();
		if (currentTotal > maxExp)
		{
			maxExp = currentTotal;
			maxDay = i;
		}
	}

	return maxDay;
}

void Expenses::filterFoodExpenses()
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	for (int i = 0; i < nrOfEntities; i++)
	{
		entities[i].setHaine(0);
		entities[i].setInternet(0);
		entities[i].setTransport(0);
		entities[i].setMenaj(0);
	}
}

void Expenses::filterFoodExpensesSmallerThan(int value)
{
	for (int i = 0; i < nrOfEntities; i++)
		previousForm[i] = entities[i];
	for (int i = 0; i < nrOfEntities; i++)
	{
		if (entities[i].getMancare() > value)
			entities[i].setMancare(0);
	}
}

void Expenses::undo()
{
	for (int i = 0; i < nrOfEntities; i++)
		entities[i] = previousForm[i];
}

#include "monthExpense.h"
#include <iostream>

monthExpense::monthExpense()
{
	menaj = 0;
	mancare = 0;
	internet = 0;
	transport = 0;
	haine = 0;
}

monthExpense::monthExpense(const monthExpense& other)
{
	this->menaj = other.menaj;
	this->mancare = other.mancare;
	this->internet = other.internet;
	this->transport = other.transport;
	this->haine = other.haine;
}

unsigned int monthExpense::getMenaj() const
{
	return menaj;
}

unsigned int monthExpense::getMancare() const
{
	return mancare;
}

unsigned int monthExpense::getInternet() const
{
	return internet;
}

unsigned int monthExpense::getTransport() const
{
	return transport;
}

unsigned int monthExpense::getHaine() const
{
	return haine;
}

void monthExpense::setMenaj(unsigned int newMenaj)
{
	menaj = newMenaj;
}

void monthExpense::setMancare(unsigned int newMancare)
{
	mancare = newMancare;
}

void monthExpense::setInternet(unsigned int newInternet)
{
	internet = newInternet;
}

void monthExpense::setTransport(unsigned int newTransport)
{
	transport = newTransport;
}

void monthExpense::setHaine(unsigned int newHaine)
{
	haine = newHaine;
}

monthExpense& monthExpense::operator=(const monthExpense& other)
{
	this->menaj = other.menaj;
	this->mancare = other.mancare;
	this->transport = other.transport;
	this->internet = other.internet;

	return *this;
}

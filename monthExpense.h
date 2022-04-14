#pragma once
#include <iostream>

class monthExpense {
public:
	// Constructors
	monthExpense();
	monthExpense(const monthExpense& other);

	// Getters

	unsigned int getMenaj() const;
	unsigned int getMancare() const;
	unsigned int getInternet() const;
	unsigned int getTransport() const;
	unsigned int getHaine() const;

	// Setters

	void setMenaj(unsigned int newMenaj);
	void setMancare(unsigned int newMancare);
	void setInternet(unsigned int newInternet);
	void setTransport(unsigned int newTransport);
	void setHaine(unsigned int newHaine);

	// Operators

	monthExpense& operator=(const monthExpense& other);

private:
	unsigned int menaj, mancare, internet, transport, haine;
};
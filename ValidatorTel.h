#pragma once
#include "Telefon.h"
#include "ValidatorSerie.h"

class ExceptieT
{
private:
	vector<string>eroare;
public:
	ExceptieT(vector<string> err);
	vector<string> getEroare() const;
};

class ValidatorTel
{
public:
	ValidatorTel() {}
	void validare(Telefon*& t);
};
#pragma once
#include"Serie.h"
#include <string>
#include <vector>
using namespace std;

class ExceptieS
{
private:
	vector<string>eroare;
public:
	ExceptieS(vector<string> err);
	vector<string> getEroare() const;
};

class ValidatorSerie
{
public:
	ValidatorSerie() {};
	void validare(Serie*& s);
};
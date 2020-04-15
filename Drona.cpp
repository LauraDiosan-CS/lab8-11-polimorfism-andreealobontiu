#include "Drona.h"

Drona::Drona():Gadget()
{
}

Drona::Drona(string p, string m, int u, int r):Gadget(p,m,u)
{
	nrRotoare = r;
}

Drona::Drona(Drona & d):Gadget(d)
{
	nrRotoare = d.nrRotoare;
}

Drona::~Drona()
{
}

int Drona::getRotoare()
{
	return nrRotoare;
}

void Drona::setRotoare(int r)
{
	nrRotoare = r;
}

void Drona::read(istream & input)
{
	string prod, model;
	int unit, rotoare;

	input >> prod;
	setNumeProd(prod);
	input >> model;
	setNumeModel(model);
	input >> unit;
	setUnitati(unit);
	input >> rotoare;
	setRotoare(rotoare);
}

void Drona::write(ostream & output)
{
	output << "Producator: " << getNumeProd() << endl;
	output << "Model: " << getNumeModel() << endl;
	output << "Nr unitati: " << getUnitati() << endl;
	output << "Nr rotoare: " << nrRotoare << endl;
}

string Drona::toString()
{
	stringstream ss;
	ss << "Drona: " << this->numeProducator << ", " << this->numeModel << ", " << this->unitatiProduse << ", " << this->nrRotoare << endl;
	return ss.str();
}

Drona* Drona::clone()
{
	Drona* newT = new Drona();
	newT->setNumeProd(numeProducator);
	newT->setNumeModel(numeModel);
	newT->setUnitati(unitatiProduse);
	newT->nrRotoare = nrRotoare;
	return newT;
}

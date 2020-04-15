#include "Gadget.h"

Gadget::Gadget()
{
	unitatiProduse = 0;
}

Gadget::Gadget(string nume, string model, int unitati)
{
	numeProducator = nume;
	numeModel = model;
	unitatiProduse = unitati;
}

Gadget::Gadget(Gadget& g)
{
	numeProducator = g.numeProducator;
	numeModel = g.numeModel;
	unitatiProduse = g.unitatiProduse;
}

Gadget::~Gadget(){}

string Gadget::getNumeProd()
{
	return numeProducator;
}

string Gadget::getNumeModel()
{
	return numeModel;
}

int Gadget::getUnitati()
{
	return unitatiProduse;
}

void Gadget::setNumeProd(string n)
{
	numeProducator = n;
}

void Gadget::setNumeModel(string m)
{
	numeModel = m;
}

void Gadget::setUnitati(int u)
{
	unitatiProduse = u;
}

bool Gadget::operator==(const Gadget & g)
{
	return tie(numeProducator, numeModel, unitatiProduse) == std::tie(g.numeProducator, g.numeModel, g.unitatiProduse);
}


Gadget& Gadget::operator=(const Gadget& g)
{
	if (this != &g) {
		numeModel = g.numeProducator;
		numeModel = g.numeModel;
		unitatiProduse=g.unitatiProduse;
	}
	return *this;
}

void Gadget::read(istream & input)
{
	input >> numeProducator;
	input >> numeModel;
	input >> unitatiProduse;
}

void Gadget::write(ostream & output)
{
	output << "Producator: " << numeProducator << endl;
	output << "Model: " << numeModel << endl;
	output << "Nr unitati: " << unitatiProduse << endl;
}

ostream & operator<<(ostream & os, Gadget * g)
{
	g->write(os);
	return os;
}

istream & operator>>(istream & input, Gadget * g)
{
	g->read(input);
	return input;
}

#include "Telefon.h"
#include <sstream>

Telefon::Telefon(): Gadget()
{
	operatoriComp = {};
}

Telefon::Telefon(string p, string m, int u, string o):Gadget(p,m,u){

	operatoriComp = o;
}

Telefon::Telefon(Telefon &t):Gadget(t)
{
	operatoriComp = t.operatoriComp;
}

Telefon::~Telefon()
{
}

string Telefon::getOperatori()
{
	return operatoriComp;
}

void Telefon::setOperatori(string o)
{
	operatoriComp = o;
}


void Telefon::read(istream & input)
{
	string prod, model, operatori;
	int unit;
	
	input >> prod;
	setNumeProd(prod);
	input >> model;
	setNumeModel(model);
	input >> unit;
	setUnitati(unit);
	input >> operatori;
	setOperatori(operatori);
}

void Telefon::write(ostream & output)
{
	output << "Producator: " << getNumeProd() << endl;
	output << "Model: " << getNumeModel() << endl;
	output << "Nr unitati: " << getUnitati() << endl;
	output << "Operatori compatibili: " << operatoriComp << endl;
}

string Telefon::toString()
{
	stringstream ss;
	ss << "Telefon: " << this->numeProducator << ", " << this->numeModel << ", " << this->unitatiProduse << ", " << this->operatoriComp << endl;
	return ss.str();
}

Telefon* Telefon::clone()
{
	Telefon* newT = new Telefon();
	newT->setNumeProd(numeProducator);
	newT->setNumeModel(numeModel);
	newT->setUnitati(unitatiProduse);
	newT->operatoriComp = operatoriComp;
	return newT;
}

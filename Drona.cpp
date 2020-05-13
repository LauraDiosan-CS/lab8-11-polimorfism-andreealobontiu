#include "Drona.h"
#include<string.h>
#include<sstream>

Drona::Drona() {
	this->rotoare = 0;
}
Drona::Drona(const char* p, const char* m, int u, int r) :Serie(p, m, u) {
	this->rotoare = r;
}

Drona::Drona(const Drona& d) :Serie(d) {
	this->rotoare = d.rotoare;
}

Drona::Drona(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	this->producator = new char[tokens[0].length() + 1];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());
	
	this->unitati = stoi(tokens[2]);
	this->rotoare = stoi(tokens[3]);
}

Drona::~Drona() {
	if (this->producator) {
		delete[] this->producator;
		this->producator = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}
Serie* Drona::clone() {
	Drona* newSerie = new Drona();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	newSerie->setRotoare(this->rotoare);
	return newSerie;
}

int Drona::getRotoare() {
	return this->rotoare;
}

void Drona::setRotoare(int r) {
	this->rotoare = r;
}

Drona& Drona::operator =(const Drona& d) {
	if (this == &d) return *this;
	if (d.producator) {
		if (this->producator) delete[] this->producator;
		this->producator = new char[strlen(d.producator) + 1];
		strcpy_s(this->producator, strlen(d.producator) + 1, d.producator);
	}
	if (d.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(d.model) + 1];
		strcpy_s(this->model, strlen(d.model) + 1, d.model);
	}
	this->unitati = d.unitati;
	this->rotoare = d.rotoare;
}

string Drona::toString() {
	string p, m;
	p = this->producator;
	m = this->model;
	return  p + " " + m + " " + to_string(this->unitati) + " " + to_string(this->rotoare);
}
string Drona::toStringDelim(char delim) {
	string p, m;
	p = this->producator;
	m = this->model;
	return  p + delim + m + delim + to_string(this->unitati) + delim + to_string(this->rotoare);
}

ostream& operator<<(ostream& os, Drona d) {
	os << d.producator << " " << d.model << " " << d.unitati << " " << d.rotoare << endl;
	return os;
}

istream& operator>>(istream& is, Drona& d) {
	cout << "Introduceti producatorul: ";
	char* p = new char[20];
	is >> p;
	
	cout << "Introduceti modelul: ";
	char* m = new char[20];
	is >> m;
	
	cout << "Introduceti numarul de unitati: ";
	int u;
	is >> u;
	
	cout << "Introduceti numarul de rotoare: ";
	int r;
	is >> r;
	
	d.setProducator(p);
	d.setModel(m);
	d.setUnitati(u);
	d.setRotoare(r);
	delete[] p;
	delete[] m;
	return is;
}
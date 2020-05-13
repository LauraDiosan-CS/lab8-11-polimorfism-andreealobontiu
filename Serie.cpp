#include "Serie.h"
#include<string.h>
#include <sstream>

Serie::Serie() {
	this->producator = NULL;
	this->model = NULL;
	this->unitati = 0;
}

Serie::Serie(const char* p, const char* m, int u) {
	if (p) {
		this->producator = new char[strlen(p) + 1];
		strcpy_s(this->producator, strlen(p) + 1, p);
	}
	
	if (model) {
		this->model = new char[strlen(m) + 1];
		strcpy_s(this->model, strlen(m) + 1, m);
	}
	
	this->unitati = u;
}

Serie::Serie(const Serie& s) {
	if (s.producator) {
		this->producator = new char[strlen(s.producator) + 1];
		strcpy_s(this->producator, strlen(s.producator) + 1, s.producator);
	}

	if (s.model) {
		this->model = new char[strlen(s.model) + 1];
		strcpy_s(this->model, strlen(s.model) + 1, s.model);
	}
	
	this->unitati = s.unitati;
}

Serie::Serie(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	this->producator = new char[tokens[0].length() + 1];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());
	unitati = stoi(tokens[2]);
}

Serie::~Serie() {
	if (this->producator) {
		delete[] this->producator;
		this->producator = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}
Serie* Serie::clone() {
	Serie* newSerie = new Serie();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	return newSerie;
}
char* Serie::getProducator() {
	return this->producator;
}

char* Serie::getModel() {
	return this->model;
}

int Serie::getUnitati() {
	return this->unitati;
}

void Serie::setProducator(const char* p) {
	if (this->producator) {
		delete[] this->producator;
	}
	this->producator = new char[strlen(p) + 1];
	strcpy_s(this->producator, strlen(p) + 1, p);
}

void Serie::setModel(const char* m) {
	if (this->model) {
		delete[] this->model;
	}
	this->model = new char[strlen(m) + 1];
	strcpy_s(this->model, strlen(m) + 1, m);
}

void Serie::setUnitati(int u) {
	this->unitati = u;
}
Serie& Serie::operator =(const Serie& s) {
	if (this == &s) return *this; //in case of self assignment
	if (s.producator) {
		if (this->producator)delete[]this->producator;
		this->producator = new char[strlen(s.producator) + 1];
		strcpy_s(this->producator, strlen(s.producator) + 1, s.producator);
	}
	
	this->unitati = s.unitati;

	if (s.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(s.model) + 1];
		strcpy_s(this->model, strlen(s.model) + 1, s.model);
	}
	
	return *this;
}

bool Serie::operator==(const Serie& s) {
	if (this->producator and s.producator and this->model and s.model) {
		return (strcmp(this->producator, s.producator) == 0) and (strcmp(this->model, s.model) == 0) and (this->unitati == s.unitati);
	}
	return false;
}

bool Serie::operator<(const Serie& s) {
	return (strcmp(this->producator, s.producator) < 0);
}
string Serie::toString() {
	string p,m;
	p = this->producator;
	m = this->model;
	return  p + " " + m + " " + to_string(this->unitati);
}
string Serie::toStringDelim(char delim) {
	string p, m;
	p = this->producator;
	m = this->model;
	return  p + delim + m + delim + to_string(this->unitati);
}
ostream& operator<<(ostream& os, Serie s) {
	os << s.producator << " " << s.model << " " << s.unitati << endl;
	return os;
}

istream& operator >>(istream& is, Serie& s) {
	cout << "Introduceti producatorul: ";
	char* p = new char[20];
	is >> p;
	cout << "Introduceti modelul: ";
	char* m = new char[20];
	is >> m;
	cout << "Introduceti numarul de unitati: ";
	int u;
	is >> u;
	int ok = 0;


	s.setProducator(p);
	s.setModel(m);
	s.setUnitati(u);
	delete[] p;
	delete[] m;
	return is;
}
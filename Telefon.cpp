#include "Telefon.h"
#include <string.h>
#include <sstream>

Telefon::Telefon() :Serie() {
	this->operatori = {};
}

Telefon::Telefon(const char* p, const char* m, int u, vector<string>o) :Serie(p, m, u) {
	this->operatori = o;
}

Telefon::Telefon(const Telefon& t) :Serie(t) {
	this->operatori = t.operatori;
}

Telefon::Telefon(string linie, char delim) {
	vector<string> tokens = splitLine(linie, delim);
	this->producator = new char[tokens[0].length() + 1];
	strcpy_s(this->producator, tokens[0].length() + 1, tokens[0].c_str());

	this->model = new char[tokens[1].length() + 1];
	strcpy_s(this->model, tokens[1].length() + 1, tokens[1].c_str());

	this->unitati = stoi(tokens[2]);
	if (tokens[3] != "nada")
	{
		vector <string> token_op = splitLine(tokens[3], ';');
		for (int i = 0; i < token_op.size(); i++) {
			this->operatori.push_back(token_op[i]);
		}
	}
}

Serie* Telefon::clone() {
	Telefon* newSerie = new Telefon();
	newSerie->setProducator(this->producator);
	newSerie->setModel(this->model);
	newSerie->setUnitati(this->unitati);
	newSerie->setOperatori(this->operatori);
	return newSerie;
}

vector<string> Telefon::getOperatori() {
	return this->operatori;
}

void Telefon::setOperatori(vector<string> o) {
	this->operatori = o;
}
Telefon::~Telefon() {
	if (this->producator) {
		delete[] this->producator;
		this->producator = NULL;
	}
	if (this->model) {
		delete[] this->model;
		this->model = NULL;
	}
}

Telefon& Telefon::operator =(const Telefon& t) {
	if (this == &t) return *this;
	if (t.producator) {
		if (this->producator)delete[]this->producator;
		this->producator = new char[strlen(t.producator) + 1];
		strcpy_s(this->producator, strlen(t.producator) + 1, t.producator);
	}
	if (t.model) {
		if (this->model)delete[]this->model;
		this->model = new char[strlen(t.model) + 1];
		strcpy_s(this->model, strlen(t.model) + 1, t.model);
	}
	this->unitati = t.unitati;
	this->operatori = t.operatori;
	return *this;
}

string Telefon::toString() {
	string p, m, o;
	p = this->producator;
	m = this->model;
	if (this->operatori.size() == 0) { o = "$$"; }
	else {
		o = this->operatori[0];
		for (int i = 1; i < this->operatori.size(); i++)
		{
			o = o + ";" + this->operatori[i];
		}
	}
	return  p + " " + m + " " + to_string(this->unitati) + " " + o;
}

string Telefon::toStringDelim(char delim) {
	string p, m, o;
	p = this->producator;
	m = this->model;
	if (this->operatori.size() == 0) { o = "nada"; }
	else {
		o = this->operatori[0];
		for (int i = 1; i < this->operatori.size(); i++)
		{
			o = o + ";" + this->operatori[i];
		}
	}
	return  p + delim + m + delim + to_string(this->unitati) + delim + o;
}

ostream& operator<<(ostream& os, Telefon t) {
	os << t.producator << " " << t.model << " " << t.unitati << " ";
	for (int i = 0; i < t.operatori.size() - 1; i++)
		os << t.operatori[i] << ";";
	os << t.operatori[t.operatori.size() - 1] << endl;
	return os;
}

istream& operator >>(istream& is, Telefon& t) {
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
	
	vector<string> operatori = {};
	cout << "Introduceti numarul de operatori: ";
	int n = 0;
	is >> n;
	
	char* o = new char[20];
	int i = 0;
	while (i < n)
	{
		cout << "Introduceti operatorul: ";
		is >> o;
		operatori.push_back(o);
		i++;
	}
	t.setProducator(p);
	t.setModel(m);
	t.setUnitati(u);
	t.setOperatori(operatori);
	delete[] p;
	delete[] m;
	return is;
}
#include "ValidatorSerie.h"
using namespace std;

ExceptieS::ExceptieS(vector<string> err) : eroare{ err } {}

vector<string> ExceptieS::getEroare() const {
	return this->eroare;
}

void ValidatorSerie::validare(Serie*& s) {
	vector<string> eroare;
	if ((*s).getUnitati() < 100) {
		eroare.push_back(string("Numarul de unitati trebuie sa fie mai mare decat 100 \n"));
	}
	if (eroare.size() > 0) throw ExceptieS(eroare);
}

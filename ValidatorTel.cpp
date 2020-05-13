#include "ValidatorTel.h"
using namespace std;

ExceptieT::ExceptieT(vector<string> err) : eroare{ err } {}
vector<string> ExceptieT::getEroare() const {
	return this->eroare;
}
void ValidatorTel::validare(Telefon*& t) {
	vector<string> eroare;
	if ((*t).getUnitati() < 100) {
		eroare.push_back("Numarul de unitati trebuie sa fie mai mare decat 100 \n");
	}
	if ((*t).getOperatori().size() < 1) {
		eroare.push_back(string("Telefonul trebuie sa aiba minim un operator \n"));

	}
	if (eroare.size() > 0) throw ExceptieT(eroare);
}
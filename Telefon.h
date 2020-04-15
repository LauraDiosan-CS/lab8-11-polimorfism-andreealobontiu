#pragma once
#include "Gadget.h"
class Telefon :
	public Gadget
{
private:
	string operatoriComp;
public:
	Telefon();
	Telefon(string p, string m, int u, string o);
	Telefon(Telefon &t);
	~Telefon();

	string getOperatori();
	void setOperatori(string o);

	void read(istream& input)override;
	void write(ostream& output)override;
	string toString() override;
	Telefon* clone()override;
};


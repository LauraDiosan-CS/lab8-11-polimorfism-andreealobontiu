#pragma once
#include "Gadget.h"
#include <sstream>
class Drona :
	public Gadget
{
private:
	int nrRotoare;
public:
	Drona();
	Drona(string p, string m, int u, int r);
	Drona(Drona &d);
	~Drona();

	int getRotoare();
	void setRotoare(int r);

	void read(istream& input)override;
	void write(ostream& output)override;
	string toString() override;
	Drona* clone()override;
};


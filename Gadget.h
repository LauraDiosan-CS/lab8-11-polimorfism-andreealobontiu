#pragma once
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

class Gadget
{
protected:
	string numeProducator;
	string numeModel;
	int unitatiProduse;
public:
	Gadget();
	Gadget(string nume, string model, int unitati);
	Gadget(Gadget &g);
	virtual ~Gadget();

	string getNumeProd();
	string getNumeModel();
	int getUnitati();

	void setNumeProd(string n);
	void setNumeModel(string m);
	void setUnitati(int u);

	friend ostream& operator<<(ostream &os, Gadget *g);
	friend istream &operator>>(istream &input, Gadget *g);

	bool operator==(const Gadget &g);
	bool operator!=(const Gadget &g);
	virtual Gadget& operator=(const Gadget &g);
	virtual void read(istream& input);
	virtual void write(ostream& output);
	virtual string toString() = 0;
	virtual Gadget* clone() = 0;
};


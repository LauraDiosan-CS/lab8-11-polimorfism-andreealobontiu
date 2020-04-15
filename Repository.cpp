#include "Repository.h"

Repository::Repository()
{
	elem = new Gadget*[50];
	size = 0;
}

Repository::Repository(string fisier):Repository()
{
	if (fisier == "csv-drone.csv")
	{
		readDrona();
	}
	else
		readTelefon();
}

Repository::~Repository()
{
	if (elem) {
		for (int i = 0; i < size; i++)
			if (elem[i]) {
				delete elem[i];
				elem[i] = NULL;
			}
		delete[] elem;
		elem = NULL;
	}
}

void Repository::readDrona()
{
	ifstream fin("csv-drona.csv");

	if (!fin.is_open())
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}


	while (fin.good())
	{
		Drona *d=new Drona();
		string p, m, u, r;

		getline(fin, p, ',');
		getline(fin, m, ',');
		getline(fin, u, ',');
		getline(fin, r, '\n');

		string prod = p;
		string model = m;
		int unit = stoi(u);
		int rot = stoi(r);
		*d = Drona(p, m, unit, rot);
		addElem(d);
		
	}
	fin.close();
}

void Repository::readTelefon()
{
	ifstream fin("csv-telefoane.csv");

	if (!fin.is_open())
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}


	while (fin.good())
	{
		Telefon *t = new Telefon();
		string p, m, u, o;

		getline(fin, p, ',');
		getline(fin, m, ',');
		getline(fin, u, ',');
		getline(fin, o, '\n');

		int unit = stoi(u);
		*t = Telefon(p, m, unit, o);
		addElem(t);

	}
	fin.close();
}

void Repository::addElem(Gadget* g)
{
	if (size == 0) {
		elem = new Gadget*[100];
	}
	elem[size] = g->clone();
	size++;
}

Gadget** Repository::getAll()
{
	return elem;
}

int Repository::getSize()
{
	return size;
}

void Repository::updateTelefon(string p, string m, int u, string o, string newP, string newM, int newU, string newO)
{
	for (int i = 0; i < getSize(); i++) {
		Telefon *el = dynamic_cast<Telefon*>(elem[i]);
		if (el != nullptr) {
			if (el->getNumeProd() == p && el->getNumeModel() == m && el->getUnitati() == u && el->getOperatori() == o) 
			{
				el->setNumeProd(newP);
				el->setNumeModel(newM);
				el->setUnitati(newU);
				el->setOperatori(newO);
			}
		}
	}
}

void Repository::updateDrona(string p, string m, int u, int r, string newP, string newM, int newU, int newR)
{
	for (int i = 0; i < getSize(); i++) {
		Drona *el = dynamic_cast<Drona*>(elem[i]);
		if (el != nullptr) {
			if (el->getNumeProd() == p && el->getNumeModel() == m && el->getUnitati() == u && el->getRotoare() == r)
			{
				el->setNumeProd(newP);
				el->setNumeModel(newM);
				el->setUnitati(newU);
				el->setRotoare(newR);
			}
		}
	}
}

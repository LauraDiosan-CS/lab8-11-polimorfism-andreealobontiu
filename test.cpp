#include "test.h"
#include <assert.h>

void testTelefon()
{
	Telefon *t = new Telefon();
	*t = Telefon();
	assert(t->getUnitati()==0);

	Telefon* t1 = new Telefon("Samsung", "galaxy", 23, "operator");
	assert(t1->getUnitati() == 23);
	assert(t1->getNumeProd() == "Samsung");
	t1->setNumeModel("note 7");
	assert(t1->getNumeModel() == "note 7");

	cout << "Testele pt Telefon functioneaza" << endl;
}

void testDrona()
{
	Drona* d = new Drona();
	*d = Drona();
	assert(d->getUnitati() == 0);
	Drona* d2 = new Drona("Firma", "asdf45", 20, 3);
	assert(d2->getUnitati() == 20);
	assert(d2->getNumeProd() == "Firma");
	d2->setRotoare(6);
	assert(d2->getRotoare() == 6);
	

	cout << "testele pt Drona functioneaza" << endl;
}

void testRepository()
{
	Repository repoD;
	Repository repoT;
	repoD.readDrona()
}

#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "Drona.h"
#include "Telefon.h"
#include "Gadget.h"
#include <fstream>
#include <istream>

using namespace std;

class Repository
{
private:
	int size;
	string fisier;
	Gadget** elem;
public:
	Repository();
	Repository(string fisier);
	~Repository();

	void readTelefon();
	void readDrona();
	void addElem(Gadget* g);
	Gadget** getAll();
	int getSize();
	void updateTelefon(string p, string m, int u, string o, string newP, string newM, int newU, string newO);
	void updateDrona(string p, string m, int u, int r, string newP, string newM, int newU, int newR);
};


#pragma once
#include "Utile.h"
#include<string>
#include<iostream>
using namespace std;

class Serie {
protected:
	char* producator;
	char* model;
	int unitati;
public:
	Serie();
	Serie(const char* p, const char* m, int u);
	Serie(const Serie& s);
	Serie(string linie, char delim);
	virtual ~Serie();
	
	virtual Serie* clone();
	char* getProducator();
	char* getModel();
	int getUnitati();
	void setProducator(const char* p);
	void setModel(const char* m);
	void setUnitati(int u);

	virtual Serie& operator= (const Serie& s);
	virtual bool operator ==(const Serie& s);
	virtual bool operator <(const Serie& s);
	friend ostream& operator <<(ostream& os, Serie s);
	friend istream& operator >>(istream& is, Serie& s);
	virtual string toString();
	virtual string toStringDelim(char delim);
};
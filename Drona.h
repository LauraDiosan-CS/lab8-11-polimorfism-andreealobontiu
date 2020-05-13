#pragma once
#include<string>
#include<iostream>
#include"Serie.h"

using namespace std;

class Drona : public Serie {
private:
	int rotoare;
public:
	Drona();
	Drona(const char* p, const char* m, int u, int r);
	Drona(const Drona& d);
	Drona(string linie, char delim);
	~Drona();
	Serie* clone();
	
	int getRotoare();
	void setRotoare(int r);

	Drona& operator=(const Drona& d);

	friend ostream& operator <<(ostream& os, Drona d);
	friend istream& operator >> (istream& is, Drona& d);
	string toString();
	string toStringDelim(char delim);
};

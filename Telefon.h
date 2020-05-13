#pragma once
#include "Serie.h"
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Telefon :public Serie {
private:
	vector<string>operatori;
public:
	Telefon();
	Telefon(const char* p, const char* m, int u, vector<string> o);
	Telefon(const Telefon& t);
	Telefon& operator= (const Telefon& t);
	Telefon(string linie, char delim); //conversie
	
	Serie* clone();
	vector<string> getOperatori();
	void setOperatori(vector<string> o);

	friend ostream& operator <<(ostream& os, Telefon t);
	friend istream& operator >>(istream& is, Telefon& t);
	string toString();
	string toStringDelim(char delim);
	~Telefon();
};
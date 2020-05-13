#pragma once
#include <sstream>
#include "Serie.h"
#include "Telefon.h"
#include "Drona.h"
#include "Serializer.h"
using namespace std;

class SerializerSerie :public Serializer<Serie*> {
public:
	SerializerSerie() {}
	inline Serie* fromString(string linie, char delim);
	~SerializerSerie() {}
};

Serie* SerializerSerie::fromString(string linie, char delim) {
	vector<string> token;
	stringstream ss(linie);
	string elem;
	while (getline(ss, elem, delim)) {
		token.push_back(elem);
	}
	if (token.size() == 4) {
		try {
			int i = stoi(token[3]);
			Serie* d = new Drona(linie, delim);
			return d;
		}
		catch (...) {
			Serie* t = new Telefon(linie, delim);
			return t;
		}
	}
}
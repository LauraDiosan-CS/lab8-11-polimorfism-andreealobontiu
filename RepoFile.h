#pragma once
#include <iostream>
#include <fstream>
#include "Telefon.h"
#include "Serializer.h"
#include "RepoTemplate.h"

using namespace std;

template<class T>
class RepoFile :public RepoTemplate<T>
{
private:
	const char* fisier;
	char delim;
	Serializer<T>* ser;

public:
	RepoFile();
	RepoFile(const char* f, const char d, Serializer<T>* s);
	int addElem(T el);
	int deleteElem(T el);
	void updateElem(T vechi, T nou);
	void loadFromFile(const char* f, const char d);
	void saveToFile();
	~RepoFile();
};

template<class T>
RepoFile<T>::RepoFile() :RepoTemplate<T>()
{
	this->fisier = "";
	this->delim = ' ';
}

template<class T>
RepoFile<T>::RepoFile(const char* f, const char d, Serializer<T>* s)
{
	this->ser = s;
	loadFromFile(f, d);
}

template<class T>
void RepoFile<T>::loadFromFile(const char* f, const char d)
{
	if (f == NULL)
	{
		cout << "Eroare la citirea fisierului" << endl;
	}
	try {
		ifstream fin(f);
		RepoTemplate<T>::clearElem();
		string linie;
		if (fin.is_open()) {
			while (getline(fin, linie))
			{
				RepoTemplate<T>::addElem(ser->fromString(linie, d));
			}
			fin.close();
		}
	}
	catch (exception e) {
		cout << "Eroare la incarcarea datelor";
	};
}

template<class T>
void RepoFile<T>::saveToFile()
{
	if (this->fisier == NULL)
		cout << "Eroare fisier" << endl;;
	ofstream fout(this->fisier);
	for (T el : this->getAll())
	{
		fout << el->toStringDelim(this->delim) << endl;
	}
	fout.close();
}

template<class T>
RepoFile<T>::~RepoFile()
{
}

template<class T>
int RepoFile<T>::addElem(T el) {
	int adaugare = RepoTemplate<T>::addElem(el);
	if (adaugare != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFile<T>::deleteElem(T el) {
	int stergere = RepoTemplate<T>::deleteElem(el);
	saveToFile();
	if (stergere != 0) {
		return 0;
	}
	else
		return -1;
}

template<class T>
void RepoFile<T>::updateElem(T vechi, T nou)
{
	RepoTemplate<T>::updateElem(vechi, nou);
	saveToFile();
}

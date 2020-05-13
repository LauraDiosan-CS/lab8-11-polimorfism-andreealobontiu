#pragma once
#include <iostream>
#include<fstream>
#include "Telefon.h"
#include "Drona.h"
#include "RepoTemplate.h"
#include "Serializer.h"
using namespace std;


template<class T>
class RepoFileHTML :public RepoTemplate<T>
{
private:
	const char* fisier;
	Serializer<T>* ser;
public:
	RepoFileHTML();
	RepoFileHTML(const char* f, Serializer<T>*s);
	int addElem(T el);
	int deleteElem(T el);
	void updateElem(T vechi, T nou);
	void loadFromFile(const char* f);
	void saveToFile();
	~RepoFileHTML();
};

template<class T>
RepoFileHTML<T>::RepoFileHTML() :RepoTemplate<T>()
{
	this->fisier = "";
}
template<class T>
RepoFileHTML<T>::RepoFileHTML(const char* f, Serializer<T>* s)
{
	this->fisier = f;
	this->ser = s;
	loadFromFile(f);
}

template<class T>
void RepoFileHTML<T>::loadFromFile(const char* f)
{
	if (f == NULL)
		cout << "Eroare la citirea fisierului" << endl;
	try {
		this->fisier = f;
		ifstream fin(f);
		RepoTemplate<T>::clearElem();
		string linie;
		if (fin.is_open()) {
			while (getline(fin, linie))
			{
				RepoTemplate<T>::addElem(ser->fromString(linie, '/'));
			}
			fin.close();
		}
	}
	catch (exception e) {
		cout << "Eroare la incarcarea datelor" << endl;
	};
}

template<class T>
void RepoFileHTML<T>::saveToFile()
{
	if (this->fisier == NULL)
		cout << "Eroare" << endl;
	ofstream fout(this->fisier);
	for (T elem : this->getAll())
	{
		fout << elem->toStringDelim('/') << endl;
	}
	fout.close();
}

template<class T>
RepoFileHTML<T>::~RepoFileHTML()
{
}

template<class T>
int RepoFileHTML<T>::addElem(T el) {
	int adaugare = RepoTemplate<T>::addElem(el);
	if (adaugare != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFileHTML<T>::deleteElem(T el) {
	int stergere = RepoTemplate<T>::deleteElem(el);
	saveToFile();
	if (stergere != 0) {
		return 0;
	}
	else
		return -1;
}

template<class T>
void RepoFileHTML<T>::updateElem(T vechi, T nou)
{
	RepoTemplate<T>::updateElem(vechi, nou);
	saveToFile();
}
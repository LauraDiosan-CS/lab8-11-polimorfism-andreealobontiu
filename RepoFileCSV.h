#pragma once
#include <iostream>
#include<fstream>
#include "RepoTemplate.h"
#include "Serializer.h"
using namespace std;

template<class T>
class RepoFileCSV :public RepoTemplate<T>
{
private:
	const char* fisier;
	Serializer<T>* ser;
public:
	RepoFileCSV();
	RepoFileCSV(const char* f, Serializer<T>* s);
	int addElem(T el);
	int deleteElem(T el);
	void updateElem(T vechi, T nou);
	void loadFromFile(const char* f);
	void saveToFile();
	~RepoFileCSV();
};

template<class T>
RepoFileCSV<T>::RepoFileCSV() :RepoTemplate<T>()
{
	this->fisier = "";
}

template<class T>
RepoFileCSV<T>::RepoFileCSV(const char* f, Serializer<T>* s)
{
	this->fisier = f;
	this->ser = s;
	loadFromFile(f);
}

template<class T>
void RepoFileCSV<T>::loadFromFile(const char* f)
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

				RepoTemplate<T>::addElem(ser->fromString(linie, ','));
			}
			fin.close();
		}
	}
	catch (exception e) {
		cout << "Eroare la incarcarea datelor";
	};
}

template<class T>
void RepoFileCSV<T>::saveToFile()
{
	if (this->fisier == NULL)
		cout << "Eroare" << endl;
	ofstream fout(this->fisier);
	for (T elem : this->getAll())
	{
		fout << elem->toStringDelim(',') << endl;
	}
	fout.close();
}

template<class T>
RepoFileCSV<T>::~RepoFileCSV()
{
}

template<class T>
int RepoFileCSV<T>::addElem(T el) {
	int adaugare = RepoTemplate<T>::addElem(el);
	if (adaugare != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFileCSV<T>::deleteElem(T el) {
	int stergere = RepoTemplate<T>::deleteElem(el);
	saveToFile();
	if (stergere != 0) {
		return 0;
	}
	else
		return -1;
}

template<class T>
void RepoFileCSV<T>::updateElem(T vechi, T nou)
{
	RepoTemplate<T>::updateElem(vechi, nou);
	saveToFile();
}
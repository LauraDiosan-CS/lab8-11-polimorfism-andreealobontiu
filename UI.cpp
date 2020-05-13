#include "UI.h"
#include <iostream>
#include "Drona.h"
#include<string.h>
using namespace std;

void UI::run()
{
	int opt, optiune;
	bool stop = false;
	while (!stop) {
		cout << "1. Log in " << endl;
		cout << "2. Exit" << endl;
		cin >> opt;
		if (opt == 1) {
			if (logIn()) {
				while (serv.logat() and !stop) {
					cout << endl;
					printMeniu();
					cin >> optiune;
					cout << endl;
					
					switch (optiune) {
					case 1: {addElem(); break; }
					case 2: {updateElem(); break; }
					case 3: {delElem(); break; }
					case 4: {findElem(); break; }
					case 5: {readSerii(); break; }
					case 6: {logOut(); cout << "Ati fost delogat" << endl; break; }
					case 0: {stop = true; cout << "Program incheiat" << endl; }
					}
				}
			}
			else { cout << "Date de autentificare incorecte" << endl; }
		}
		else {
			if (opt == 2) {
				stop = true;
				cout << "Program incheiat" << endl;
			}
		}
	}
}

void UI::printMeniu()
{
	cout << "---------MENIU---------" << endl << endl;
	cout << "1. Adauga o serie" << endl;
	cout << "2. Actualizeaza o serie" << endl;
	cout << "3. Sterge o serie " << endl;
	cout << "4. Cauta dupa producator " << endl;
	cout << "5. Arata lista de serii" << endl;
	cout << "6. Log out" << endl;
	cout << "0. Exit" << endl;
	cout << "Introduceti optiunea dorita: ";
}

void UI::addElem() {
	int optiune;
	cout << "Tipul de serie pe care doriti sa-l adaugati:" << endl;
	cout << "1. Drona" << endl;
	cout << "2. Telefon" << endl;
	try {
		cin >> optiune;
		Serie* serie;
		if (optiune == 1) {
			try {
				Drona d;
				cin >> d;
				serie = d.clone();
				serv.addElem(serie);
				delete[]serie;
			}
			catch (ExceptieS exc)
			{
				for (int i = 0; i < exc.getEroare().size(); i++)
					cout << exc.getEroare()[i];
			}
		}
		else {
			try {
				Telefon t;
				cin >> t;
				serie = t.clone();
				serv.addElem(serie);
				delete[]serie;
			}
			catch (ExceptieT exc2) {
				for (int j = 0; j < exc2.getEroare().size(); j++)
					cout << exc2.getEroare()[j];
			}
		}
	}
	catch (exception e) { cout << "Exceptie ->" << e.what() << endl; }
}



void UI::findElem() {
	string prod;
	cout << "Introduceti producatorul: ";
	cin >> prod;
	list<Serie*> list_rez = serv.findProducator(prod);
	list <Serie*>::iterator it;
	for (it = list_rez.begin(); it != list_rez.end(); ++it) {
		cout << (*it)->toString() << endl;
	}
}

void UI::delElem() {
	cout << "Tipul de serie pe care doriti sa o stergeti: " << endl;
	cout << "1. Drona" << endl;
	cout << "2. Telefon" << endl;
	try {
		int optiune;
		cin >> optiune;
		Serie* serie;
		if (optiune == 1)
		{
			Drona d;
			cin >> d;
			serie = d.clone();
		}
		else {
			Telefon t;
			cin >> t;
			serie = t.clone();
		}
		serv.deleteElem(serie);
		cout << "Seria a fost stearsa" << endl;
		delete[]serie;
	}
	catch (exception e) { cout << "Exceptie ->" << e.what() << endl; }
}


int UI::logIn()
{
	string username, parola;
	cout << "Username: ";
	cin >> username;
	cout << "Parola: ";
	cin >> parola;
	return serv.login(username, parola);
}

void UI::logOut() {
	serv.logout();
}

void UI::readSerii() {
	for (int i = 0; i < serv.getSize(); i++)
	{
		cout << (*serv.getElemIndex(i)).toString() << endl;
	}
}


void UI::updateElem() {
	int optiune;
	cout << "Introduceti tipul de serie pe care doriti sa o actualizati: " << endl;
	cout << "1. Drona" << endl;
	cout << "2. Telefon" << endl;
	try {
		cin >> optiune;
		Serie* serie;
		Serie* newSerie;
		if (optiune == 1) {
			Drona d, newD;
			cin >> d;
			serie = d.clone();
			cout << "Introduceti datele noii serii de drona: " << endl;
			cin >> newD;
			newSerie = newD.clone();
		}
		else {
			Telefon t, newT;
			cin >> t;
			serie = t.clone();
			cout << "Introduceti datele noii serii de telefon: " << endl;
			cin >> newT;
			newSerie = newT.clone();
		}
		serv.updateElem(serie, newSerie);
		delete[]serie;
		delete[]newSerie;
	}
	catch (exception e) { cout << "Exceptie -> " << e.what() << endl; }
}

UI::~UI()
{

}
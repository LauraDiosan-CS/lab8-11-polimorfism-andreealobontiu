#include "Service.h"
#include "User.h"
#include "Drona.h"
#include "ValidatorTel.h"
#include "ValidatorSerie.h"
#include <sstream>
#include <algorithm>
using namespace std;


bool Service::login(string u, string p)
{
	User* user = new User(u, p);
	this->user_logat = (*user);
	return ((repoUser.findElem(user) != -1) and (!this->user_logat.getUsername().empty()));
}

bool Service::logat() {
	return !this->user_logat.getUsername().empty();
}

void Service::logout()
{
	this->user_logat.setUsername("");
	this->user_logat.setParola("");
}

list<Serie*> Service::getAllSerie()
{
	return this->repo.getAll();
}

list<Serie*> Service::findProducator(string prod) {
	list<Serie*>list_rez;
	list<Serie*>serii = repo.getAll();
	list <Serie*>::iterator it;
	string produc;
	for (it = serii.begin(); it != serii.end(); ++it)
	{
		if (prod == (*it)->getProducator())
		{
			list_rez.push_back(*it);
		}
	}
	return list_rez;

}
int Service::getSize() {
	return this->repo.getSize();
}

Serie* Service::getElemIndex(int index) {
	return (this->repo.getElemIndex(index));
}

bool Service::verifNr(const string& s)
{
	return !s.empty() && (count_if(s.begin(), s.end(), isdigit) == s.size());
}

void Service::addElem(Serie*& s) {
	vector<string> token;
	string linie = s->toStringDelim('|');
	stringstream ss(linie);
	string elem;
	while (getline(ss, elem, '|')) {
		token.push_back(elem);
	}
	if (token.size() == 4) {
		if (verifNr(token[3])) {
			int i = stoi(token[3]);
			Serie* d = new Drona(linie, '|');
			valid_s.validare(d);
			repo.addElem(d);
			delete[]d;
		}
		else {
			Serie* s = new Telefon(linie, '|');
			Telefon* t = new Telefon(linie, '|');
			valid_t.validare(t);
			repo.addElem(s);
			delete[]t;
			delete[]s;
		}
	}
}

void Service::deleteElem(Serie*& s) {
	if (repo.findElem(s) == -1) 
	{
		cout << "Elementul nu a fost gasit" << endl;
	}
	else 
	{
		repo.deleteElem(s);
	}
}
void Service::updateElem(Serie* s, Serie*& newS) {
	if (repo.findElem(s) == -1) {
		cout << "Elementul nu a fost gasit" << endl;
	}
	else {
		repo.updateElem(s, newS);
	}
}

Service::~Service()
{
}
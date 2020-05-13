#pragma once
#include "RepoTemplate.h"
#include "User.h"
#include "Serie.h"
#include "Telefon.h"
#include "ValidatorTel.h"
#include "ValidatorSerie.h"

class Service
{
private:
	RepoTemplate<Serie*>& repo;
	RepoTemplate<User*>& repoUser;
	User user_logat;;
	ValidatorSerie valid_s;
	ValidatorTel valid_t;
public:
	Service(RepoTemplate<Serie*>& repoS, RepoTemplate<User*>& repoU) :repo(repoS), repoUser(repoU) { repo = repoS; repoUser = repoU; };
	bool login(string u, string p);
	bool logat();
	void logout();
	bool verifNr(const string& s);
	list<Serie*> findProducator(string prod);
	list<Serie*> getAllSerie();
	int getSize();
	Serie* getElemIndex(int index);
	void addElem(Serie*& s);
	void deleteElem(Serie*& s);
	void updateElem(Serie* s, Serie*& newS);
	~Service();
};
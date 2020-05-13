#pragma once
#include "Service.h"
class UI {
private:
	Service serv;
public:
	UI(Service& s) : serv(s) {};
	int logIn();
	void logOut();
	void addElem();
	void findElem();
	void updateElem();
	void delElem();
	void readSerii();
	void printMeniu();
	void run();
	~UI();
};
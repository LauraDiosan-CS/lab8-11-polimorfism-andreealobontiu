#include "Teste.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
#include <list>

using namespace std;

void testTelefon()
{
	vector<string> operatori;
	string op1;
	op1 = "telekom";
	operatori.push_back(op1);

	Telefon t1 = Telefon();
	assert(t1.getProducator() == NULL);
	assert(t1.getModel() == NULL);
	assert(t1.getUnitati() == 0);
	assert(t1.getOperatori().size() == 0);

	Telefon t2("tel2", "model2", 123, operatori);
	assert(strcmp(t2.getProducator(),"tel2") == 0);
	//assert(strcmp(t2.getModel(), "model2") == 0);
	assert(t2.getUnitati() == 123);
	assert(t2.getOperatori()[0] == "telekom");
	assert(t2.getOperatori().size() == 1);
	
	Telefon t3(t2);
	assert(strcmp(t2.getProducator(), t3.getProducator()) == 0);
	assert(t2.getUnitati() == t3.getUnitati());
	
	Telefon t4("tel4 model4 123 vodafone", ' ');
	assert(strcmp(t4.getProducator(), "tel4") == 0);
	assert(strcmp(t4.getModel(), "model4") == 0);
	assert(t4.getUnitati() == 123);
	assert(t4.getOperatori()[0] == "vodafone");

	Telefon t5;
	t5 = t4;
	assert(strcmp(t5.getProducator(), t4.getProducator()) == 0);
	assert(t4==t5);

	t5.setModel("alabala");
	assert(strcmp(t5.getModel(), "alabala") == 0);
	cout << "Testele Telefon functioneaza" << endl;
}

void testDrona()
{
	Drona t1 = Drona();
	assert(t1.getProducator() == NULL);
	assert(t1.getModel() == NULL);
	assert(t1.getUnitati() == 0);

	Drona t2("drona2", "model2", 123, 13);
	assert(strcmp(t2.getProducator(), "drona2") == 0);
	//assert(strcmp(t2.getModel(), "model2") == 0);
	assert(t2.getUnitati() == 123);
	assert(t2.getRotoare() == 13);

	Drona t3(t2);
	assert(strcmp(t2.getProducator(), t3.getProducator()) == 0);
	assert(t2.getUnitati() == t3.getUnitati());

	Drona t4("drona4 model4 123 3", ' ');
	assert(strcmp(t4.getProducator(), "drona4") == 0);
	assert(strcmp(t4.getModel(), "model4") == 0);
	assert(t4.getUnitati() == 123);
	assert(t4.getRotoare() == 3);

	Drona t5;
	t5 = t4;
	assert(strcmp(t5.getProducator(), t4.getProducator()) == 0);
	assert(t4 == t5);

	t5.setProducator("alabala");
	assert(strcmp(t5.getProducator(), "alabala") == 0);
	cout << "Testele Drona functioneaza" << endl;
}

void testRepoTemplate() {
	vector<string> operatori;
	string op1, op2;
	op1 = "telekom";
	op2 = "vodafone";
	operatori.push_back(op1);
	operatori.push_back(op2);
	RepoTemplate<Serie*> repo;
	
	Serie* s1 = new Telefon("tel1", "model1", 123, operatori);
	Serie* s2 = new Telefon("tel2", "model2", 123, operatori);
	Serie* s3 = new Telefon("tel3", "model3", 345, operatori);
	Serie* s4 = new Telefon("tel4", "model4", 154, operatori);
	
	repo.addElem(s1);
	repo.addElem(s2);
	repo.addElem(s3);
	repo.addElem(s4);
	
	assert(repo.getSize() == 4);
	assert(*repo.getAll().front() == *s1);
	assert(*repo.getAll().back() == *s4);
	assert(*repo.getElemIndex(1) == *s2);
	assert(repo.findElem(s3) == 3);

	repo.deleteElem(s2);
	assert(repo.getSize() == 3);
	assert(repo.findElem(s2) == -1);
	
	Serie* telUpdate = new Telefon("tel5", "model5", 123, operatori);
	repo.updateElem(s1->clone(), telUpdate->clone());
	assert(repo.findElem(s1) == -1);
	
	delete[]s1;
	delete[]s2;
	delete[]s3;
	delete[]s4;
	delete[]telUpdate;
	cout << "Testele RepoTemplate functioneaza" << endl;
}


void testRepoFileCSV() {
	SerializerSerie* ser = new SerializerSerie();
	RepoFileCSV<Serie*> repof("Serii.csv", ser);
	vector<string> operatori;
	string op1, op2;
	op1 = "telekom";
	op2 = "vodafone";
	operatori.push_back(op1);
	operatori.push_back(op2);
	assert(repof.getSize() == 6);
	
	Serie* t1 = new Telefon("aaa", "aaa", 123, operatori);
	repof.addElem(t1);
	assert(repof.getSize() == 7);
	assert(repof.findElem(t1) == 6);
	repof.deleteElem(t1);
	assert(repof.getSize() == 6);
	assert(repof.findElem(t1) == -1);
	
	list<Serie*> list_rez = repof.getAll();
	assert(list_rez.size() == 6);

	repof.addElem(t1);
	Serie* t2 = new Telefon("bbb", "bbb", 123, operatori);
	repof.updateElem(t1, t2);
	assert(repof.findElem(t1) == -1);
	
	delete[]t1;
	delete[]t2;

	cout << "Testele RepoFileCSV functioneaza" << endl;
}

void testRepoFileHTML() {
	SerializerSerie* ser = new SerializerSerie();
	RepoFileHTML<Serie*> repof("Serii.html", ser);
	vector<string> operatori;
	string op1, op2;
	op1 = "telekom";
	op2 = "vodafone";
	operatori.push_back(op1);
	operatori.push_back(op2);
	
	Serie* t1 = new Telefon("aaa", "aaa", 123, operatori);
	repof.addElem(t1);
	assert(repof.getSize() == 7);
	assert(repof.findElem(t1) == 6);
	repof.deleteElem(t1);
	assert(repof.getSize() == 6);
	assert(repof.findElem(t1) == -1);

	list<Serie*> list_rez = repof.getAll();
	assert(list_rez.size() == 6);

	repof.addElem(t1);
	Serie* t2 = new Telefon("bbb", "bbb", 123, operatori);
	repof.updateElem(t1, t2);
	assert(repof.findElem(t1) == -1);

	delete[]t1;
	delete[]t2;

	cout << "Testele RepoFileHTML functioneaza" << endl;
}

void testService() {
	SerializerSerie* s = new SerializerSerie();
	SerializerUser* u = new SerializerUser();
	RepoFileCSV<Serie*> repof("Serii.csv", s);
	RepoFile<User*> repoU("Users.txt", ' ', u);
	Service serv(repof, repoU);
	
	User* u1 = new User("andreea", "1234");
	repoU.addElem(u1);
	assert(serv.login("andreea", "1234") == 1);
	assert(serv.login("maria", "1234") == 0);
	Serie* s1 = new Drona("aaa", "aaa", 123, 12);
	serv.addElem(s1);
	
	assert((serv.getAllSerie()).size() == 7);
	serv.deleteElem(s1);
	assert(serv.getAllSerie().size() == 6);

	serv.addElem(s1);
	Serie* sUpdate = new Drona("bbb", "bbb", 344, 5);
	serv.updateElem(s1, sUpdate);
	list<Serie*> list_rez = serv.findProducator("bbb");
	assert(list_rez.size() == 1);
	
	delete[] s1;
	delete[] sUpdate;
}
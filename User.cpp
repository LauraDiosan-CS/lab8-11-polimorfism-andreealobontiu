#include "User.h"
#include <vector>
#include "Utile.h"
using namespace std;

User::User()
{
}

User::User(string u, string p) :username(u), parola(p)
{
}

User::User(string linie, char delim) {
	vector<string> token = splitLine(linie, delim);
	this->username = token[0];
	this->parola = token[1];
}

User* User::clone() {
	User* newUser = new User();
	newUser->setUsername(this->username);
	newUser->setParola(this->parola);
	return newUser;
}

string User::getUsername()
{
	return this->username;
}

string User::getParola()
{
	return this->parola;
}

void User::setUsername(string u)
{
	this->username = u;
}

void User::setParola(string p)
{
	this->parola = p;
}

bool User::operator==(const User& u)
{
	return (username == u.username) and (parola == u.parola);
}

string User::toString()
{
	return username + " " + parola;
}

string User::toStringDelim(char delim)
{
	return username + delim + parola;
}

User::~User()
{
}
#pragma once
#include <string>
using namespace std;

class User
{
private:
	string username;
	string parola;
public:
	User();
	User(string linie, char delim);
	User(string u, string p);
	//void fromString(string linie, char delim);
	User* clone();
	string getUsername();
	string getParola();
	void setUsername(string u);
	void setParola(string p);
	bool operator==(const User& u);
	string toString();
	string toStringDelim(char delim);
	~User();
};
#pragma once
#include <sstream>
#include "User.h"
#include "Telefon.h"
#include "Serializer.h"
class SerializerUser :public Serializer<User*> {
public:
	SerializerUser() {}
	inline User* fromString(string, char);
	~SerializerUser();
};

User* SerializerUser::fromString(string linie, char delim) {
	vector<string> token;
	stringstream ss(linie);
	string elem;
	while (getline(ss, elem, delim)) {
		token.push_back(elem);
	}
	User* u = new User(linie, delim);
	return u;

}

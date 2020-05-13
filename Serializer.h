#pragma once
using namespace std;

template <class T> class Serializer {
public:
	Serializer() {};
	virtual T fromString(string linie, char delim) = 0;
	~Serializer() {};
};
#include "Utile.h"
#include <sstream>
#include <iostream>
using namespace std;

vector<string> splitLine(string linie, char delim)
{

	stringstream ss(linie);
	string ob;
	vector<std::string> elem;
	while (getline(ss, ob, delim)) {
		elem.push_back(ob);
	}
	return elem;
}

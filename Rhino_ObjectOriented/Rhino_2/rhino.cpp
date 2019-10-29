#include "rhino.h"

Rhino::Rhino()
{
	cout << "Calling default constructor ... " << endl;
	nickname = " ";
	year = 2013;
}

Rhino::Rhino(string n, int y, int m, char g)
{
	cout << "Calling Nondefault constructor ... " << endl;
	nickname = n;
	year = y;
}

Rhino::~Rhino()
{
	cout << "Calling destructor ..." << endl;
}

string Rhino::getName()
{
	return nickname;
}


void Rhino::setTag(int t)
{
	tag = t;
}
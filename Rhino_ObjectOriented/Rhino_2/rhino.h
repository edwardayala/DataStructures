#include <iostream>
#include <string>

using namespace std;

class Rhino
{
public:
	//Constructors
	Rhino();
	Rhino(string n, int y, int m, char g);
	~Rhino();

	string getName();
	void setTag(int t);

private:
	string nickname;
	int year;
};

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Rhino
{
public:
	//Constructors
	Rhino();
	Rhino(string n, int y, int m, char g);
	Rhino(string n, int y, int m, char g, int t, Rhino * mom, Rhino * dad);
	~Rhino();
	
	void setName(string nm);
	string getName();

	void setBirthYear(int y);
	int getYear();

	void setBirthMonth(int m);
	int getMonth();

	void setGender(char g);
	char getGender();

	void setTag(int t);
	int getTag();

	int getNumChildren();

	void addMother(Rhino * mom);
	void addFather(Rhino * dad);
	
	Rhino * getMother();
	Rhino * getFather();

	bool isMale();

	void print();
	
	bool isMotherOf(Rhino e);
	bool isFatherOf(Rhino e);
	bool isParentOf(Rhino e);
	bool isSisterOf(Rhino e);
	bool isYounger(Rhino f);

private:
	string nickname;	// Rhino's name - string
	int year;			// Rhino's birth year - int
	int month;			// Rhino's birth month - int
	char gender;		// Rhino's gender - char - 'M' = male | 'F' = female
	int tag;			// Rhino's tag status - int | -1 = no tag | (+) = tag
	int children;		// Number of rhino's children
	Rhino * mother;
	Rhino * father;
	Rhino * r;
};

#include "rhino.h"

int main()
{
	Rhino r1;
	Rhino r2("Travis", 2012, 12, 'M');

	Rhino * r3;

	r3 = new Rhino("Julie", 2011, 1, 'F');

	cout << r1.getName() << endl;
	cout << r2.getName()<< endl;
	cout << r3->getName()<< endl;

	r3->setName("Sherry");
	cout << r3->getName()<< endl;

	//delete r3;

	return 0;
}
#include <iostream>
#include "rhino.h"

using namespace std;

int numCorrectAns = 0;

void check(string question, bool studentAns, bool correctAns)
{
	cout << question << ": " << (studentAns == correctAns? "Passed": "Failed") << endl;
	if(studentAns == correctAns)
		numCorrectAns++;
}

int main()
{
	Rhino Kibibbi("Kibibbi", 1939, 1, 'F');
	Rhino Jimma("Jimma", 1935, 2, 'M');
	Rhino Ikenna("Ikenna", 1999, 11, 'F');
	Ikenna.addFather(&Jimma);
	Rhino Bubba("Bubba", 1960, 11, 'M', 52, &Kibibbi, &Jimma);
	Rhino Juba("Juba", 1950, 5, 'M');
	Juba.addMother(&Kibibbi);
	Juba.setTag(10);
	Rhino Kojo("Kojo", 1994, 8, 'M', 1234, &Ikenna, &Juba);
	Rhino Sefu("Sefu", 1994, 12, 'F');
	Sefu.addFather(&Bubba);

	Juba.print();
	Kibibbi.print();
	Bubba.print();

	cout << endl;
	check(  "Kibbibi.isMotherOf(Juba)? " , Kibibbi.isMotherOf(Juba), true) ;
	check(  "Kibbibi.isMotherOf(Ikenna)? " , Kibibbi.isMotherOf(Ikenna), false)  ;
	check(  "Juba.isFatherOf(Kojo)? " , Juba.isFatherOf(Kojo), true)  ;
	check(  "Juba.isFatherOf(Ikenna)? " , Juba.isFatherOf(Ikenna), false)  ;
	check(  "Kibbibi.isParentOf(Juba)? " , Kibibbi.isParentOf(Juba), true) ;
	check(  "Kibbibi.isParentOf(Ikenna)? " , Kibibbi.isParentOf(Ikenna), false)  ;
	check(  "Ikenna.isSisterOf(Bubba)? " , Ikenna.isSisterOf(Bubba), true)  ;
	check(  "Ikenna.isSisterOf(Juba)? " , Ikenna.isSisterOf(Juba), false)  ;
	check(  "Sefu.isYounger(Kojo)? " , Sefu.isYounger(Kojo), true)  ;
	check(  "Juba.isYounger(Kojo)? " , Juba.isYounger(Kojo), false)  ;

	cout << "The number of correct answers is " << numCorrectAns << endl;
	system("PAUSE");
	return 0;
}

/*

Male rhino Juba. Born 5/1950. Tag 10. Mother Kibibbi. Children 1.
Female rhino Kibibbi. Born 1/1939. Children 2.
Male rhino Bubba. Born 11/1960. Tag 52. Mother Kibibbi. Father Jimma. Children 1.

Kibbibi.isMotherOf(Juba)? : Passed
Kibbibi.isMotherOf(Ikenna)? : Passed
Juba.isFatherOf(Kojo)? : Passed
Juba.isFatherOf(Ikenna)? : Passed
Kibbibi.isParentOf(Juba)? : Passed
Kibbibi.isParentOf(Ikenna)? : Passed
Ikenna.isSisterOf(Bubba)? : Passed
Ikenna.isSisterOf(Juba)? : Passed
Sefu.isYounger(Kojo)? : Passed
Juba.isYounger(Kojo)? : Passed
The number of correct answers is 10
Press any key to continue . . .

*/
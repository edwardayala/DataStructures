//The program will be used to test students' Rhino class
//Students' programs should output exactly same messages 
//as output by this test program if correct.

#include <iostream>
#include "rhino.h"

using namespace std;

void print(Rhino * p)
{
	cout << "**************Rhino info**************" << endl;
	cout << "Name:\t\t" << p->getName() << endl;
	cout << "Born:\t\t" << p->getMonth() << '-' << p->getYear() << endl;
	cout << "Gender:\t\t" << p->getGender() << endl;
	cout << p->getName() << " is " << (p->isMale()?"male":"female") << endl;
	cout << "Tag:\t\t" << p->getTag() << endl;
	cout << "Children:\t" << p->getNumChildren() << endl;
	if(p->getMother() != NULL)
		cout << "Mother:\t\t" << p->getMother()->getName() << endl;
	if(p->getFather() != NULL)
		cout << "Father:\t\t" << p->getFather()->getName() << endl;

	cout << endl;
}

int main()
{
	Rhino * p1 = new Rhino("Kibibbi", 1939, 1, 'F');   //A female rhino
	Rhino p2("Jimma", 1942, 11, 'M');				//A male rhino
	Rhino p3("Juba", 1950, 5, 'M', 10, p1, &p2);

	print(p1);
	print(&p2);
	print(&p3);

	Rhino p4("Jimma's mother", 1930, 12, 'F');
	Rhino p5("Jimma's father", 1913, 10, 'M');
	p2.setTag(2345);
	p2.addMother(&p4);
	p2.addFather(&p5);
	print(&p2);
	
	delete p1;
	return 0;
}

//**************Rhino info**************
//Name:           Kibibbi
//Born:           1-1939
//Gender:         F
//Kibibbi is female
//Tag:            -1
//Children:       1
//
//**************Rhino info**************
//Name:           Jimma
//Born:           11-1942
//Gender:         M
//Jimma is male
//Tag:            -1
//Children:       1
//
//**************Rhino info**************
//Name:           Juba
//Born:           5-1950
//Gender:         M
//Juba is male
//Tag:            10
//Children:       0
//Mother:         Kibibbi
//Father:         Jimma
//
//**************Rhino info**************
//Name:           Jimma
//Born:           11-1942
//Gender:         M
//Jimma is male
//Tag:            2345
//Children:       1
//Mother:         Jimma's mother
//Father:         Jimma's father
//
//Press any key to continue . . .
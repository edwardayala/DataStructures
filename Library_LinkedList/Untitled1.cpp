#include <iostream>
#include "library.h"

using namespace std;

int main()
{
	Library test;
	Book * aBook = new Book(123);
	test.insertBook(aBook);
	aBook = new Book(456);
	test.insertBook(aBook);
	aBook = new Book(789);
	test.insertBook(aBook);
	cout << "1st print ( " << test.numBooksInLibrary() << " )\n";
	test.printLibrary();

	cout << "*make empty*\n";
	test.makeEmpty();
	cout << "2nd print( " << test.numBooksInLibrary() << " )\n";
	test.printLibrary();

	system("pause");
	
}

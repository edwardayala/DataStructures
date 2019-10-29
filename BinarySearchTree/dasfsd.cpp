// Test main file for each function 

#include <string>
#include "library.h"

using namespace std;

int main()
{
	int isbns[10] = {5,9,7,3,8,12,6,4,20,2};
	
	Library * lb = new Library();
	
	for (int i=0; i<10; i++)
	{
		Book * bk = new Book(isbns[i]);
		lb->insertBook(bk);
	}
	
	cout << "# of books in library = " << lb->lengthIs() << endl;
	cout << "height of library = " << lb->heightIs() << endl;
	cout << "max isbn in library = " << lb->getMaxBook()->getInfo() << endl;
	
	lb->printInOrder();
	lb->printPreOrder();
	lb->printPostOrder();
	
	bool fd = false;
	lb->retrieveBook(8, fd);
	if (fd)
		cout << "\n\nBook with isbn of 8 has been found." << endl;
	else
		cout << "\nBook with isbn of 8 has not been found." << endl;

	lb->retrieveBook(11, fd);

	if (fd)
		cout << "Book with isbn of 11 has been found." << endl;
	else
		cout << "Book with isbn of 11 has not been found." << endl;

	cout << "\nAfter deleting the book with isbn of 4";
	lb->deleteBook(4);
	lb->printInOrder();

	cout << "\n\nAfter deleting the book with isbn of 12";
	lb->deleteBook(12);
	lb->printInOrder();

	cout << "\n\nAfter deleting the book with isbn of 9";
	lb->deleteBook(9);
	lb->printInOrder();

	cout << endl;

	delete lb;
	return 0;
}

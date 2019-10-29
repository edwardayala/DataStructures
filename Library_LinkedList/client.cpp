// Library with books in unsorted order using linked list implementation
// Author by Yukong Zhang
// Jan 21, 2015

#include <iostream>
#include "library.h"

using namespace std;

int main()
{ 
  Library wesleyanLib;

  int number;
  bool found;
  char command;

  cout << "Enter a command: " << endl;
  cout <<"I: insert; D: delete; S: search; P: print; Q: quit" << endl;
  cin >> command;
  
  while (command != 'Q' && command != 'q')
  { 
	switch(command)
	{
	case 'i':
		case 'I':
		{
		  cout << "Enter the isbn: " << endl;
		  cin >> number;		
		  Book * aBook = new Book(number);
		  wesleyanLib.insertBook(aBook);
		  break;
		}
		case 'd':
		case 'D':
		{
		  cout << "Enter the isbn: " << endl;
		  cin >> number;
		  wesleyanLib.deleteBook(number);
		  break;
		}
		case 's':
		case 'S': 
		{
		  cout << "Enter the isbn: " << endl;
		  cin >> number;
		  found = wesleyanLib.searchBook(number);
		  if (found)
			cout << number << " found in list." << endl;
		  else cout << number  << " not in list."  << endl;  
		  
		  break;
		}
		case 'p':
		case 'P':
		{
		  wesleyanLib.printLibrary();
		  break;
		}
	}	
	cout << "Enter a command" << endl;
	cin >> command;
  }

  Library computerScienceLib(wesleyanLib);
  cout << "The number of books in Wesleyan library is " << wesleyanLib.numBooksInLibrary() << endl;
  cout << "The number of books in CSC library is " << computerScienceLib.numBooksInLibrary() << endl;

  cout << "The books in Wesleyan library are " << endl;
  wesleyanLib.printLibrary();

  cout << "Making Wesleyan library empty ..." << endl;
  wesleyanLib.makeEmpty();
  cout << "The number of books in Wesleyan library is " << wesleyanLib.numBooksInLibrary() << endl;

  cout << "The number of books in OTHER library is " << computerScienceLib.numBooksInLibrary() << endl;
  cout << "\nThe books in CSC library are "  << endl;
  computerScienceLib.printLibrary();
  cout << endl;
  system("pause");
  return 0;
};

//Sample Test output:
//
//Enter a command:
//I: insert; D: delete; S: search; P: print; Q: quit
//I
//Enter the isbn:
//123
//Enter a command
//I
//Enter the isbn:
//456
//Enter a command
//I
//Enter the isbn:
//789
//Enter a command
//P
//789
//456
//123
//Enter a command
//S
//Enter the isbn:
//456
//456 found in list.
//Enter a command
//S
//Enter the isbn:
//741
//741 not in list.
//Enter a command
//D
//Enter the isbn:
//456
//Enter a command
//P
//789
//123
//Enter a command
//D
//Enter the isbn:
//123
//Enter a command
//P
//789
//Enter a command
//D
//Enter the isbn:
//789
//Enter a command
//P
//Enter a command
//I
//Enter the isbn:
//741
//Enter a command
//I
//Enter the isbn:
//852
//Enter a command
//I
//Enter the isbn:
//963
//Enter a command
//P
//963
//852
//741
//Enter a command
//Q
//The number of books in Wesleyan library is 3
//The number of books in CSC library is 3
//The books in Wesleyan library are
//963
//852
//741
//Making Wesleyan library empty ...
//The number of books in Wesleyan library is 0
//
//The books in CSC library are
//741
//852
//963
//
//Press any key to continue . . .
#include "book.h" 

class Library 
{
public:
  Library();         //Default constructor. 
  Library(const Library & rhs); //Copy Constructor
  ~Library();        //Destructor that cleans up dynamically allocated memories when this library is destroyed.
  
  //Return true if a book with isbn of s is in this library, otherwise return false
  bool searchBook(int s);

  //Insert a book pointed by "b" into this library
  void insertBook(Book * b);

  //Delete a book with isbn of s from this library
  void deleteBook(int s);

  //Print all the book in this library
  void printLibrary();

  //Print the number of books in this library
  int numBooksInLibrary();

  //Delete all books and make this library empty
  void makeEmpty();

private:
  int numOfBooks;    //The number of books in the library presently
  Book * first;  //A pointer to the first book in this library
};


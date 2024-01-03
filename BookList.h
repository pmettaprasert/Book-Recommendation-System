// Author: Phubeth Mettaprasert
// File: BookList.h
// Date: 22/04/2022
// Purpose: A class designed to store information on the books that are being
//          rated. Each book will be stored in a dynamically allocated array
//          where the information stored will a Book struct. The methods in this
//          class are designed to either retrieve information about the books or
//          store books.

#ifndef P1_BOOKLIST_H
#define P1_BOOKLIST_H

#include <string>
using namespace std;

class BookList {

public:

    BookList(int);
    // Constructor that initializes the BookList class.
    // preconditions: Assume that cap (the array capacity int) to be used
    //                as the argument for this constructor is greater than zero.
    // postconditions: Certain private fields are set to zero (isbnCounter,
    //                 capacity, numElements) and set the array size to that of
    //                 the argument. The pointer blist should point to the
    //                 dynamically allotted array.


    ~BookList();
    // Destructor for the BookList class
    // preconditions: none
    // postconditions: The dynamically stored array will be deleted.

    BookList(const BookList&);
    // Copy constructor. Will create another BookList object base on all
    // the data created by another BookList object created already.
    // preconditions: A BookList object needs to exist before calling this
    //                copy constructor to be used as the argument.
    // postconditions: Creates a new BookList object based on the previous
    //                 BookList object.

    BookList& operator=(const BookList &);
    // Overloaded operator method. In this case used to set one BookList
    // object equal to another created BookList. Difference between copy
    // constructor and this is that this requires that a BookList object be
    // created before copying from the other BookList object.
    // preconditions: At least two BookList objects needed to exist in order
    //                copy from one BookList to the other
    // postconditions: Copies one BookList object information to the other
    //                 BookList object and returns the reference to the
    //                 copied BookList object.


    void add(string,string,string);
    // Add a book struct to a slot in the array. The method will take in the
    // author, the title and year the book is published all as a string. If the
    // array is too small, it will be adjusted accommodate the new incoming
    // book struct.
    // preconditions: Add all the requirements as string as the year will be
    //                converted in the method to int.
    // postconditions: A struct Book will be added to the end of the array. A
    //                 counter for the ISBN and the numElement will increment
    //                 as well. The struct will also be added an ISBN number
    //                 based on the ISBN counter.

    bool empty() const;
    // Checks if the array is empty.
    // preconditions: none
    // postconditions: none

    int size() const;
    // Returns the size of the array.
    // preconditions: none
    // postconditions: none

    string to_string() const;
    // A to string method that will return all the books and their respective
    // information such as ISBN, title, author and year.
    // preconditions: none
    // postconditions: none

    string newestBook() const;
    // Returns the string of the last book to be added which includes the
    // ISBN, title, author and year.
    // preconditions: At least one book must exist.
    // postconditions: none

    string getBook(int) const;
    // Returns the string of the book according to the ISBN number. This
    // should include ISBN, title, author and year.
    // preconditions: At least one book must exist as well as the method call
    //                must subtract one from the argument due to the off by
    //                one (the first book starts at one rather than at zero).
    //                This will ensure the correct ISBN number to access the
    //                correct book.
    // postconditions: none

private:

    //Struct Book containing information of the book.
    struct Book{
        string author;
        string title;
        int year;
        int isbn;
    };

    //Initialize a pointer of the Book struct which will point to the first
    // item in the array
    Book * blist;

    //Keeps track of the isbn of each book (just a counter)
    int isbnCounter;

    //Keeps track of the capacity of the array
    int capacity;

    //Keeps track of the number of elements in the array
    int numElements;

    void resize();
    // Resizes the array when it is filled.
    // preconditions: Assume that array can be expanded enough as to not
    //                memory leak.
    // postconditions: The array will be double the current capacity, with
    //                 the pointer still pointing to the same array.

};

#endif //P1_BOOKLIST_H

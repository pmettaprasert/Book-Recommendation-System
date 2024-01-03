// Name: Phubeth Mettaprasert
// File: BookList.cpp
// Date: 22/04/2022
// Implementation for the BookList class. Creates an array to store books
// and other methods to access information from the array.

#include "BookList.h"
#include <sstream>


BookList::BookList(int cap) {

    //Use the initialized pointer to point to a new array of Book structs.
    blist = new Book[cap];

    //Set the capacity to that inputted when initializing the BookList object
    capacity = cap;
    numElements = 0;
    isbnCounter = 0;
}

BookList::~BookList() {

    //Delete the array
    delete [] blist;
}

BookList::BookList(const BookList &obj) {

    //Copies the capacity, isbn and number of elements attributes
    capacity = obj.capacity;
    numElements = obj.numElements;
    isbnCounter = obj.isbnCounter;

    // allocate memory based on new capacity
    blist = new Book[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        blist[i] = obj.blist[i];
}

BookList& BookList::operator=(const BookList &obj) {

    //Need to check if this is the object as the one being on the other side
    // of the operator
    if (this != &obj) {

        //If it is not, need to deallocate memory
        delete [] blist;

        //Copies the capacity and the number of elements based of the argument
        capacity = obj.capacity;
        numElements = obj.numElements;
        isbnCounter = obj.isbnCounter;

        // allocate memory based on new capacity
        blist = new Book[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            blist[i] = obj.blist[i];
    }
    //Return a BookList
    return *this;
}

void BookList::add(string author, string title, string year) {

    //Check if the array is all filled, if it is then resize it
    if (numElements >= capacity)
        resize();

    //Create a book struct
    Book tempBook;

    //Store information read and inputted into this method into each struct
    // field
    tempBook.author = author;
    tempBook.title = title;
    tempBook.year = stoi(year);
    tempBook.isbn = isbnCounter;

    //Add the struct to the array
    blist[numElements] = tempBook;

    //Increment each time a struct is added to keep track of the array size
    // and the isbn counter.
    numElements++;
    isbnCounter++;
}

bool BookList::empty() const {

    //If empty the return false.
    return numElements == 0;
}

int BookList::size() const {

    //Return the number of elements
    return numElements;
}

void BookList::resize() {

    //Double the capacity
    capacity *=2;

    //Create a temporary pointer
    Book *tempArr = new Book[capacity];

    //Store information from the original array to the temp array
    for(int i = 0; i < numElements; i++) {
        tempArr[i] = blist[i];
    }

    //Delete the previous array
    delete [] blist;

    //Point to the new array instead
    blist = tempArr;
}


string BookList::to_string() const {

    //Will read information from the struct and display the author
    // name, the title and the year published.
    stringstream ss;
    for (int i = 0; i < numElements; i++)
        ss << blist[i].isbn << ", " << blist[i].author << ", " <<
           blist[i].title << ", " << blist[i].year << endl;
    return ss.str();
}

string BookList::newestBook() const {

    //Will return a string of the last book in the array.
    stringstream ss;
    ss << (blist[numElements-1].isbn) + 1<< ", " <<
    blist[numElements-1].author << ", " << blist[numElements-1].title <<
    ", " << blist[numElements-1].year << endl;
    return ss.str();
}

string BookList::getBook(int isbnNo) const {

    //Will return a string of the book based off the ISBN given from the
    // argument.
    stringstream ss;
    ss << (blist[isbnNo].isbn) + 1 << ", " << blist[isbnNo].author << ", " <<
       blist[isbnNo].title << ", " << blist[isbnNo].year;
    return ss.str();
}
// Name: Phubeth Mettaprasert
// File: RatingList.cpp
// Date: 22/04/2022
// Implementation for the RatingList class. Creates a dynamic 2D array that
// will store the various ratings in rows corresponding to members and by
// columns corresponding to the various books.

#include "RatingList.h"
#include <iostream>


RatingList::RatingList(int row, int column) {

    //Set the number of reviews to zero
    reviews = 0;

    //Set the row and columns to what is inputted in order to create the size
    // of the 2D array.
    this->row = row;
    this->column = column;


    //Created the 2D array
    intArray = new int*[row];

    //Initialize the intArray
    for (int i = 0; i < row; i++)
        intArray[i] = new int[column];

    //Initialized all values in the 2D array to be 0 in order to prevent errors
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            intArray[i][j] = 0;
        }
    }

}

RatingList::~RatingList() {

    //Delete the allocated intArray
    for (int i = 0; i < column; i++)
        delete[] intArray[i];
    delete[] intArray;
}

RatingList::RatingList(const RatingList &obj) {

    //Copies the row and column and the number of reviews
    row = obj.row;
    column = obj.column;
    reviews = obj.reviews;

    // allocate memory based on new capacity
    intArray = new int* [row];

    //Initialize the column part of the intArray
    for (int i = 0; i < row; i++)
        intArray[i] = new int[column];

    //Initialize the array to zeroes first.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            intArray[i][j] = 0;
        }
    }

    //Copy the values into the created intArray
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            intArray[i][j] = obj.intArray[i][j];
        }
    }
}

RatingList& RatingList::operator=(const RatingList &obj) {

    //Need to check if this is the object as the one being on the other side
    // of the operator
    if (this != &obj) {

        //If it is not, need to deallocate memory
        for (int i = 0; i < column; i++)
            delete[] intArray[i];
        delete[] intArray;

        //Copies the capacity and the number of elements based of the argument
        row = obj.row;
        column = obj.column;
        reviews = obj.reviews;

        // allocate memory based on new capacity
        intArray = new int* [row];

        //Initialize the column part of the intArray
        for (int i = 0; i < row; i++)
            intArray[i] = new int[column];

        //Initialize the array to zeroes first.
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                intArray[i][j] = 0;
            }
        }

        //Copy the values into the created intArray
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                intArray[i][j] = obj.intArray[i][j];
            }
        }
    }
    //Return a RatingList object
    return *this;
}

void RatingList::add(int rating, int counterForName, int counterForBooks) {

    //If the row or column trying to access the array is greater than the
    // array itself, resize it.
    if((counterForName >= row) || (counterForBooks >= column)) {
        resize();
    }

    //Using the parameter rating add the rating at the correct location in
    // the 2D array
    intArray[counterForName][counterForBooks] = rating;

    //Increment no of reviews
    reviews++;

}

int RatingList::changeRating(int rating, int nameIndex, int
    bookIndex) {

    //Access the spot in the array where the rating needs to be changed.
    intArray[nameIndex][bookIndex] = rating;

    //Return the rating number as well.
    return intArray[nameIndex][bookIndex];

}

int RatingList::getRating(int nameIndex, int bookIndex) {

    //Return the rating for that location in the array
    return intArray[nameIndex][bookIndex];
}


bool RatingList:: empty() const {

    //Return true or false if it is empty
    return reviews == 0;

}

void RatingList::printOutArray(int counterForName, int counterForBook ) const {

    //For every loop prints out the rows (the members should signify the rows)
    for (int i = 0; i < counterForName; i++) {

        //The inside loop prints the review scores. (the columns should
        // signify the columns)
        for (int j = 0; j < counterForBook; j++) {
            cout << intArray[i][j] << " ";
        }
        cout << endl;
    }

}

void RatingList::resize() {

    //Double the size of the rows and column
    int tempRow = row *2;
    int tempColumn = column * 2;

    //Created a new array completely
    int ** tempIntArray;
    tempIntArray = new int * [tempRow];
    for (int i = 0; i < tempRow; i++)
        tempIntArray[i] = new int[tempColumn];

    //Initialize the tempIntArray to zero
    for (int i = 0; i < tempRow; i++) {
        for (int j = 0; j < tempColumn; j++) {
            tempIntArray[i][j] = 0;
        }
    }

    //Transfer the number from intArray to tempIntArray
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            tempIntArray[i][j] = intArray[i][j];
        }
    }

    //Delete original array
    for (int i = 0; i < column; i++)
        delete[] intArray[i];
    delete[] intArray;


    //Reset the row and column to that of temp numbers
    row = tempRow;
    column = tempColumn;

    //Point the intArray to the new tempIntArray
    intArray = tempIntArray;

}



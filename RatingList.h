// Author: Phubeth Mettaprasert
// File: RatingList.h
// Date: 22/04/2022
// Purpose: A class designed to store the ratings of the books in a 2D array.
//          The 2D array will be dynamically allocated. All methods are either
//          designed to alter the 2D array or get information related to the
//          ratings from the 2D array.


#ifndef P1_RATINGLIST_H
#define P1_RATINGLIST_H

#include <string>
using namespace std;

class RatingList {
public:
    RatingList(int, int);
    // Constructor that initializes the RatingList class.
    // preconditions: Assume that row and column (the 2D array capacity ) to
    //                be used as the argument for this constructor is greater
    //                than zero.
    // postconditions: Certain private fields are set to zero. Initialize the
    //                 2D array from the given argument inputted. Initialize
    //                 the 2D array to be all zeroes.

    ~RatingList();
    // Destructor to deallocate dynamic memory and erase the array.
    // preconditions: none
    // postconditions: The dynamic memory created from the array will be
    //                 deallocated.

    RatingList(const RatingList&);
    // Copy constructor. Will create another RatingList object base on all
    // the data created by another RatingList object created already.
    // preconditions: A RatingList object needs to exist before calling this
    //                copy constructor to be used as the argument.
    // postconditions: Creates a new RatingList object based on the previous
    //                 RatingList object.

    RatingList& operator=(const RatingList &);
    // Overloaded operator method. In this case used to set one RatingList
    // object equal to another created RatingList. Difference between copy
    // constructor and this is that this requires that a RatingList object be
    // created before copying from the other RatingList object.
    // preconditions: At least two RatingList objects needed to exist in
    //                order to copy from one RatingList to the other
    // postconditions: Copies one RatingList object information to the other
    //                 RatingList object and returns the reference to the
    //                 copied MemberList object.

    void add(int, int, int);
    // Adds a rating to the 2D array. Takes in the rating number, the
    // counterForName int which will specify the row, and the
    // counterForBook in which will specify the column.
    // preconditions: The counterForName and counterForBook will be kept
    //                track from the main driver function from reading the file.
    // postconditions: A number will be stored in the 2D array where the
    //                 row for the counterForName and the column for the
    //                 counterForBook will be stored.

    bool empty() const;
    // Checks if the array is empty.
    // preconditions: none
    // postconditions: none

    void printOutArray(int,int) const;
    // Prints out the 2D array where the parameters are the counterForName
    // and counterForBook
    // preconditions: none
    // postconditions: none

    int changeRating(int, int, int);
    // A method to change the rating where it takes in three parameters
    // where one is the rating number and the other respond to the column and
    // row that will be changed. The row will correspond to the account
    // number and the column will respond to the book isbn. Returns the new
    // rating number as well.
    // preconditions: none
    // postconditions: It will change the rating of one of the member's book
    //                 rating in the 2D array depending on the rating number
    //                 and the row and column number.

    int getRating(int, int);
    // A method to get the rating with the parameter being the row and the
    // column number.
    // preconditions: none
    // postconditions: none


private:
    int ** intArray; //Pointer to the 2D array
    int reviews; //A counter to keep track of how many reviews have been input
    int row; //The number of rows the 2D array has
    int column; //The number of columns the 2D array has

    void resize();
    // Resizes the array when it is filled.
    // preconditions: Assume that array can be expanded enough as to not
    //                memory leak.
    // postconditions: The array will be double the current capacity, with
    //                 the pointer still pointing to the same array.

};


#endif //P1_RATINGLIST_H

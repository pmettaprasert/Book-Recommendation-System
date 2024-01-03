// Author: Phubeth Mettaprasert
// File: MemberList.h
// Date: 22/04/2022
// Purpose: A class designed to hold the list of members using a dynamically
//          allocated array. Each member will be stored as a struct containing
//          information pertinent to the member. The methods in this class are
//          either used to add members or gather information about the member
//          stored.


#ifndef P1_MEMBERLIST_H
#define P1_MEMBERLIST_H

#include <string>
using namespace std;

class MemberList {

public:
    MemberList(int);
    // Constructor that initializes the MemberList class.
    // preconditions: Assume that cap (the array capacity int) to be used
    //                as the argument for this constructor is greater than zero.
    // postconditions: Certain private fields are set to zero (numElements
    //                 and accountNum) and set the capacity to int argument.
    //                 Will create a dynamic array of the struct Member type
    //                 based of the capacity inputted.

    ~MemberList();
    // Destructor to deallocate dynamic memory and erase the array.
    // preconditions: none
    // postconditions: The dynamic memory created from the array will be
    //                 deallocated.

    MemberList(const MemberList&);
    // Copy constructor. Will create another MemberList object base on all
    // the data created by another MemberList object created already.
    // preconditions: A MemberList object needs to exist before calling this
    //                copy constructor to be used as the argument.
    // postconditions: Creates a new MemberList object based on the previous
    //                 MemberList object.

    MemberList& operator=(const MemberList &);
    // Overloaded operator method. In this case used to set one MemberList
    // object equal to another created MemberList. Difference between copy
    // constructor and this is that this requires that a MemberList object be
    // created before copying from the other MemberList object.
    // preconditions: At least two MemberList objects needed to exist in
    //                order to copy from one MemberList to the other
    // postconditions: Copies one MemberList object information to the other
    //                 MemberList object and returns the reference to the
    //                 copied MemberList object.

    void add(string);
    // Adds another member which will add another Member struct to the array.
    // preconditions: Assume the name of the member for the parameter when
    //                inputted will be of string type.
    // postconditions: A struct Member will be added at the end of the array.
    //                 If the array is too small it will be resized. Counters
    //                 for numElements and accountNum will be incremented by
    //                 one every time add is called.

    bool empty() const;
    // Checks if the array is empty.
    // preconditions: none
    // postconditions: none

    int size() const;
    // Returns the size of the array.
    // preconditions: none
    // postconditions: none

    string to_string() const;
    // A to string method that will return all the members and their
    // corresponding account number.
    // preconditions: none
    // postconditions: none

    string newestMember() const;
    // A method used to return information on the last member that was
    // stored.
    // preconditions: none
    // postconditions: none

    string getMember(int) const;
    // Returns the member name when inputted of the member account number.
    // preconditions: Assume that the account number is within range of the
    //                array. The driver file should contain checks for input.
    // postconditions: none

private:

    //The struct Member to be stored in the array.
    struct Member {
        string name; //The name of the member
        int account; //Account number for the member
    };
    Member * mlist; //Pointer for the array.
    int accountNum; //Keeps track of account number when adding new members.
    int capacity; //Current capacity of the array.
    int numElements; //The current amount of elements in the array

    void resize();
    // Resizes the array when it is filled.
    // preconditions: Assume that array can be expanded enough as to not
    //                memory leak.
    // postconditions: The array will be double the current capacity, with
    //                 the pointer still pointing to the same array.

};


#endif //P1_MEMBERLIST_H

// Name: Phubeth Mettaprasert
// File: MemberList.cpp
// Date: 22/04/2022
// Implementation for the MemberList class. Creates an array to store members
// and other methods to access information from the array.
#include <sstream>
#include "MemberList.h"



MemberList::MemberList(int cap) {

    //Initialized the pointer dynamically with the parameter cap.
    mlist = new Member[cap];

    //Initialized fields with capacity to cap, and the other to zero
    capacity = cap;
    numElements = 0;
    accountNum = 0;
}

MemberList::~MemberList() {

    //Delete the array
    delete [] mlist;
}

MemberList::MemberList(const MemberList &obj) {

    //Copies the capacity and number of elements attributes
    capacity = obj.capacity;
    numElements = obj.numElements;
    accountNum = obj.accountNum;

    // allocate memory based on new capacity
    mlist = new Member[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        mlist[i] = obj.mlist[i];
}

MemberList& MemberList::operator=(const MemberList &obj) {

    //Need to check if this is the object as the one being on the other side
    // of the operator
    if (this != &obj) {

        //If it is not, need to deallocate memory
        delete [] mlist;

        //Copies the capacity and the number of elements based of the argument
        capacity = obj.capacity;
        numElements = obj.numElements;
        accountNum = obj.accountNum;

        // allocate memory based on new capacity
        mlist = new Member[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            mlist[i] = obj.mlist[i];
    }
    //Return a MemberList
    return *this;
}

void MemberList::add(string name) {

    //Check if the array is all filled, if it is then resize it
    if (numElements >= capacity)
        resize();

    //Create a Member struct
    Member tempMember;

    //Store the struct with name given from the parameter and an account
    // number being kept throughout using a counter
    tempMember.name = name;
    tempMember.account = accountNum;


    //Add the struct to the array
    mlist[numElements] = tempMember;

    //Increment each time a struct is added to keep track of the array size
    // and the account number.
    numElements++;
    accountNum++;
}

bool MemberList::empty() const {

    //If empty the return false.
    return numElements == 0;
}

int MemberList::size() const {

    //Return the number of elements
    return numElements;
}

void MemberList::resize() {

    //Double the capacity
    capacity *=2;

    //Create a temporary pointer
    Member *tempArr = new Member[capacity];

    //Store information from the original array to the temp array
    for(int i = 0; i < numElements; i++) {
        tempArr[i] = mlist[i];
    }

    //Delete the previous array
    delete [] mlist;

    //Point to the new array instead
    mlist = tempArr;
}



string MemberList::to_string() const {

    //Create a stringstream object
    stringstream ss;

    //Store each member's name and account number in the stringstream.
    for (int i = 0; i < numElements; i++)
        ss << mlist[i].name << ", " << mlist[i].account  << endl;

    //Return the stringstream string
    return ss.str();
}

string MemberList::newestMember() const {

    //Create a stringstream object
    stringstream ss;

    //Stores the last members information in the string stream
    ss << mlist[numElements-1].name << "(account #: " <<
    (mlist[numElements-1].account) + 1 << ") was added." << endl;

    //Return the stringstream string
    return ss.str();
}

string MemberList::getMember(int memberNumber) const {

    //Create a stringstream object
    stringstream ss;

    //Using the parameter memberNumber, return the name of that memberNumber
    ss << mlist[memberNumber].name ;

    //Return the stringstream string
    return ss.str();
}


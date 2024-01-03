// Phubeth Mettaprasert
// File: p1.cpp
// Date: 22/04/2022
// Purpose: This program is designed to be user interface to create an
//          account, store various books' reviews, view the reviews and be
//          recommended books the user might like.
// Input: Takes in the filenames for the book ratings and the list of books.
// Process: The files inputted will populate the arrays created from the
//          various classes created. The user will then be able to store
//          information about their book ratings, view what they've reviewed,
//          view recommendations and add members or review new books. The
//          arrays created to store this information will expand as more
//          users or book reviews are added.
// Output: User should be guided by the menu through the various functions.
//         The menu will perform actions to display various information. In
//         the end the user will be allowed to quit the program.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BookList.h"
#include "MemberList.h"
#include "RatingList.h"

using namespace std;

string promptFileBook();
// Prompt the user for the book filename.
// IN: none
// MODIFY: none.
// OUT: Returns the string of the prompted file name.

string promptRating();
// Prompt the user for the ratings' filename.
// IN: none
// MODIFY: none.
// OUT: Returns the string of the prompted file name.

void printIntro();
// Print the introduction text.
// IN: none
// MODIFY: none.
// OUT: none

BookList storeBook();
// Reads the file prompted by the promptFileBook() and then stores the
// information in a BookList object which will be store the information about
// the book in an array of book structs.
// IN: Will be prompted for a text file name.
// MODIFY: Modifies the declared variable BookList bookList to be a copy of
//         bookList object created in this function.
// OUT: A BookList object that will be stored in the bookList variable.

RatingList storeRatingAndMember (MemberList&, int&, int&);
// Reads the file prompted by the promptRating and then stores the
// information in a RatingList object which will store the information in a
// 2D array of ratings. The MemberList object passed in by reference will
// also be altered to the store the list of members read from the same file.
// IN: The MemberList object declared in main and the two int counter
//     (counterMember and counterBook) which keeps track of the number of books
//     and number of names read in the main loop.
// MODIFY: The MemberList object will then store the list of member's names
//         in its respective struct and each time a name is added or
//         book rating is added, increment the two int counters.
// OUT: A RatingList object which will store all the ratings from the file
//      read. The returned object will then be put into the ratingList variable.

int promptFirstMenu(BookList&, MemberList&, RatingList&,int& ,int&);
// The function will prompt the various different option before the login
// menu. The options are, add a new member, add a new book, login and quit.
// Quit will quit and exit the program. the other options will then be used
// to do other functions.
// IN: The BookList object reference, the MemberList object reference, the
//     RatingList object reference and the two int counter that keeps track
//     of names and the amount of books rated.
// MODIFY: In this function, it should not modify anything, but when it is
//         broken down to other options where it will call other functions, it
//         will modify the objects inputted here
// OUT: Returns an int which is used in the main loop to determine whether to
//      quit the program or not.

void memberLoginOptions(MemberList&, BookList&, RatingList&, int, int&, int&);
// This function will show the various options available after logging in as
// a member. The options are, add a new member, add a new book, rate a book,
// view current member's ratings, see book recommendations and logout. Each
// option will branch off into their respective functions.
// IN: Takes in the MemberList object reference, the BookList object
//     reference, the RatingLists object reference, the int memberNumber
//     (passed on from the promptFirstMenu option 3) and the two int counter
//     that keeps track  of names and the amount of books rated.
// MODIFY: In this function, it should not modify anything, but when it is
//         broken down to other options where it will call other functions, it
//         will modify the objects inputted here
// OUT: Returns nothing.

void addNewBook(BookList&, int&);
// Adds a new book to the BookList object.
// IN: The BookList object reference and the counterBook reference which is
//     keeping track of the amount of books stored in the BooKList object in
//     the main driver. Inside the function will be several prompts to store
//     the necessary information to add a book.
// MODIFY: When a new book is added, the counterBook is incremented by one.
//         The BookList object will store a new book along with the
//         information inputted from user.
// OUT: none

void addNewMember(MemberList&, int&);
// Adds a new member to the MemberList object.
// IN: The MemberList object reference and the counterMember reference which is
//     keeping track of the amount of members stored in the MemberList object
//     in the main driver. Inside the function will be several prompts to store
//     the necessary information to add a member.
// MODIFY: When a new member is added, the counterMember is incremented by one.
//         The MemberList object will store a new member along with
//         information inputted from user.
// OUT: none

void rateBook(BookList&, RatingList&, int);
// Rates a book whether the book has a rating or not. Will be prompted to
// enter the ISBN number of the book in order to rate the book.
// IN: The BookList object reference, the RatingList object reference and the
//     memberNumber passed fon from the memberLoginOption menu.
// MODIFY: Modifies the RatingList so that correct row (using the
//         memberNumber) and correct column (using the BookList object) will
//         have the new int rating.
// OUT: none

void viewRating(BookList&,RatingList&, MemberList&, int , int);
// Prints out the current ratings for the current member.
// IN: BookList object reference, RatingList object reference, MemberList
//     object reference, the memberNumber and the bookCounter
// MODIFY: none
// OUT: prints out the current ratings of the member currently logged in.

int compareRating(int, int, RatingList&, MemberList&);
// A function that calculates the dot product between the various members'
// rating. This in turn finds the highest dot product and determines that
// member has the highest similar taste in book as the current member.
// IN: The memberNumber (current logged in member), the counterBook (the
//     counter of books added kept track in main), the RatingList object
//     reference and the MemberList object reference.
// MODIFY: none.
// OUT: Outputs an int which is the index (member number) that has the
//      highest dot product score for the current logged-in user.

void displayLikes(int, int , RatingList&, MemberList&, BookList&);
// Displays the member who has similar tastes in books as the current
// logged-in member. Will call another function that will show the
// recommended books.
// IN: The memberNumber (current logged in member), the counterBook (the
//     counter of books added kept track in main), the RatingList object
//     reference, the BookList object reference and the MemberList object
//     reference.
// MODIFY: none.
// OUT: Prints out the member with the highest similar taste and their
//      recommendation for books.

void displayRecommend(int, int, int, RatingList&, MemberList&, BookList&);
// Displays the list of recommended books with similar taste to the current
// logged-in user.
// IN: memberNumber (current logged in member number), counterBook which is
//     the counter of books added kept track in main, the recommendMember
//     index, the RatingList object reference, the BookList object reference
//     and the MemberList object reference.
// MODIFY: none.
// OUT: Prints out the list of all the books that are recommended to the
//      current logged-in user.


int main() {

    //Print introduction text
    printIntro();

    //Initialize and store the BookList object
    BookList bookList = storeBook();

    //Initialize and store the MemberList object
    MemberList memberList(10);

    //Initialize counters to keep track in the main driver
    int counterMember = 0;
    int counterBook = 0;

    //Created and modified the memberlist as well as the rating list
    RatingList ratingList = storeRatingAndMember(memberList,
                                        counterMember,counterBook);


    //Prints out the number of books and members
    cout << endl << "# of books:" << bookList.size() << endl;
    cout << "# of members:" << memberList.size() << endl;

    //Zero means keep going and one means to stop the loop.
    int quitLoop;
    do {
        quitLoop = promptFirstMenu(bookList, memberList, ratingList,
                                   counterBook, counterMember);
    } while (quitLoop == 0);


}

string promptFileBook() {

    //Ask for the file name of the books.
    cout << "\nEnter books file:";
    string bookFileName;
    cin >> bookFileName;
    cin.ignore();
    return bookFileName;
}

void printIntro() {
    cout << "\nWelcome to the Book Recommendation Program.\nThis is a program "
             << "designed to archive members and provide the members\nwith a"
            << " rating system for books. Enjoy the program!" << endl;
}

string promptRating() {

    //Ask for the ratings list file
    cout << "Enter rating file:";
    string ratingFile;
    cin >> ratingFile;
    cin.ignore();
    return ratingFile;
}

BookList storeBook() {

    //Create a BookList object of size 10
    BookList readBookFile(10);

    //Initialize variables to used to store the various information from
    // reading the file. Keep a counter to keep track of what to store in the
    // switch statement.
    int counter = 0;
    string author;
    string year;
    string title;
    string filename;


    //Stores the read line delimited by newline in variable str
    string str;

    //Stores the read line delimited by comma in variable commaStr
    string commaStr;

    //An integer check to keep prompting for a filename until a right
    // filename is inputted.
    int doWhileCheck = 1;

    //Do while loop that will keep asking for the correct file
    do {

        //Prompt for book name
        filename = promptFileBook();

        //Create ifstream of the file read
        ifstream infile;
        infile.open(filename);

        //Check if the file exist
        if (infile) {

            //If file opens correctly will break out of this do-while loop
            doWhileCheck =0;

            //Read only each line delimited by a newline
            while (getline(infile, str, '\n')) {

                //Use a stringstream to read the one line from the file
                stringstream ss(str);

                //Read each part of the string delimited by the comma
                while (getline(ss, commaStr, ',')) {

                    //Using a counter to keep track of what is being read in the
                    // string
                    switch (counter) {

                        //Reads the author
                        case 0:
                            author = commaStr;
                            counter++;
                            break;

                        //Reads the title of the book
                        case 1:
                            title = commaStr;
                            counter++;
                            break;

                        //Reads the year of the book
                        case 2:
                            year = commaStr;
                            counter = 0;
                            readBookFile.add(author, title, year);
                            break;

                        //Necessary default or else the IDE throws a warning.
                        default:
                            break;
                    }
                }
            }

            infile.close();

        } else {

            //Displays message when file is not opened properly
            cout << "Error opening the file\n" << "Please enter a valid book "
                                                  "file\n";
        }

    } while (doWhileCheck == 1);



    //Return BookList object
    return readBookFile;
}

RatingList storeRatingAndMember (MemberList& memberList, int & counterMember,
                                 int& counterBook) {

    //Create a new RatingList object
    RatingList ratingList(1,1);

    //Initialize the various variables to store information
    string line, intLine, filename;
    ifstream infile;

    //A do-while loop to prompt the user to put in the correct file name.
    int doWhileCheck = 1;

    do {
        //Prompt for the file
        filename = promptRating();

        //Open the file
        infile.open(filename);
        if (infile) {

            //Break out of the do-while loop once the file read
            doWhileCheck = 0;
            while (getline(infile, line)) {

                //The first line adds the member name to the memberList object
                memberList.add(line);

                //Keep reading in order to store the ratings
                getline(infile, intLine);
                istringstream stringStream(intLine);
                string word;

                //Keeps track of how many books rated per member
                counterBook = 0;
                while (stringStream >> word) {

                    //Convert to int
                    int num = stoi(word);

                    //Add the rating corresponding to the current member read
                    // in this file in the  ratingList object
                    ratingList.add(num, counterMember, counterBook);
                    counterBook++;
                }
                counterMember++;

            }
        } else {

            //Displays message when file is not opened properly
            cout << "Error opening the file\n" << "Please enter a valid "
                                                  "ratings file\n";
        }
    } while (doWhileCheck == 1);

    infile.close();

    return ratingList;

}

int promptFirstMenu(BookList & bookList, MemberList & memberList, RatingList
& ratingList, int& counterBook, int& counterMember) {

    //Display the non logged in menu
    cout << endl <<
            "************** MENU **************" << endl <<
            "* 1. Add a new member            *" << endl <<
            "* 2. Add a new book              *" << endl <<
            "* 3. Login                       *" << endl <<
            "* 4. Quit                        *" << endl <<
            "**********************************" << endl <<
            endl << "Enter a menu option:";

    //The various options that the user can take
    string option, memberString;
    int memberNumber;
    cin >> option;
    int intOption = stoi(option);
    switch (intOption) {

        //Case 1 adds a new member
        case 1:
            addNewMember(memberList, counterMember);
            return 0;

        //Case 2 adds a new book
        case 2:
            addNewBook(bookList, counterBook);
            return 0;

        //Case 3 is to login
        case 3:

            //Prompt and check for valid member number
            cout << "Enter member account:";
            cin >> memberString;
            memberNumber = stoi(memberString);
            memberNumber -= 1;
            if(memberNumber < 0 || memberNumber > memberList.size()) {
                cout << "Please enter a valid member account number." << endl;
                return 0;
            }
            memberLoginOptions(memberList, bookList, ratingList,
                               memberNumber, counterMember, counterBook);
            return 0;

        //Case 4 quits the program
        case 4:
            cout << "\nThank you for using the Book Recommendation Program!";
            return 1;
        default:
            cout << "Please enter a valid option number.";
            return 0;

    }
}

void memberLoginOptions(MemberList& memberList, BookList& bookList,
                        RatingList& ratingList, int memberNumber, int&
                        counterMember, int& counterBook) {

    string option;
    int intOption;

    //Print out current logged in member
    cout << memberList.getMember(memberNumber) << ", you are logged in!" <<
        endl;

    //A do-while loop that provides the logged in member choices of what to
    // do, only at option 6 will the loop break.
    do {
        cout << endl <<
             "************** MENU **************" << endl <<
             "* 1. Add a new member            *" << endl <<
             "* 2. Add a new book              *" << endl <<
             "* 3. Rate book                   *" << endl <<
             "* 4. View ratings                *" << endl <<
             "* 5. See recommendations         *" << endl <<
             "* 6. Logout                      *" << endl <<
             "**********************************" << endl <<
             endl << "Enter a menu option:";

        cin >> option;
        intOption = stoi(option);

        //Presented with various options
        switch (intOption) {
            case 1:
                addNewMember(memberList, counterMember);
                break;
            case 2:
                addNewBook(bookList, counterBook);
                break;
            case 3:
                rateBook(bookList, ratingList, memberNumber);
                break;
            case 4:
                viewRating(bookList, ratingList, memberList,
                           memberNumber, counterBook);
                break;
            case 5:
                displayLikes(memberNumber, counterBook, ratingList,
                             memberList, bookList);
                break;
            case 6:
                break;

            //Performs a catch-all for the invalid option number.
            default:
                cout << endl << "Please enter a valid option number." << endl;
                break;

        }
    } while (intOption != 6);
}

void addNewBook(BookList &bookList, int& counterBook) {

    //Prompts for information and adds the new book. Keeps track of how many
    // books have been added to the BookList object with the counterBook.
    string author, title, year;
    cout << "Enter the author of the new book:";
    cin.ignore();
    getline(cin, author);
    cout << "Enter the title of the new book:";
    getline(cin, title);
    cout << "Enter the year (or range of years) of the new book:";
    getline(cin, year);
    bookList.add(author, title, year);
    counterBook++;

    //Prints out the last book added
    cout << bookList.newestBook();
}

void addNewMember(MemberList &memberList, int& counterMember) {

    //Prompts for information and adds the new member. Keeps track of how many
    // members have been added to the MemberList object with the counterMember.
    string name;
    cout << "Enter the name of the new member:";
    cin.ignore();
    getline(cin, name);
    memberList.add(name);
    counterMember++;

    //Prints out the last member added
    cout << memberList.newestMember();
}

void rateBook(BookList &bookList, RatingList &ratingList, int memberNumber) {

    //Prompt the for the Isbn of the book to  rate
    string isbnString;
    int isbn, rating, newRating;
    char confirm;
    cout << "Enter the ISBN for the book you'd like to rate:";
    cin >> isbn;

    //Offset by one.
    int trueIsbn = isbn-1;

    //Performs check if the isbn is in the correct range
    if (!(trueIsbn < 0 || trueIsbn > bookList.size())) {

        //Checks if the book has been rated or not. 0 means not rated yet.
        if (ratingList.getRating(memberNumber, trueIsbn) == 0) {
            cout << "Enter your rating:";
            cin >> rating;

            //Performs check for only these numbers allowed for the rating
            if(rating == -5 || rating == -3 || rating == 0 || rating == 1 ||
            rating == 3 || rating == 5) {

                //Added the new rating to the correct member (row) and right
                // book based on Isbn (column)
                newRating = ratingList.changeRating(rating, memberNumber,
                                                    trueIsbn);
                cout << "Your new rating for " << bookList.getBook(trueIsbn) <<
                     "=> rating: " << newRating << endl;
            } else {
                cout << "Please input a valid rating.";
            }
        } else {

            //If the rating is not zero then the user has a choice of whether
            // to replace current rating or not
            cout << "Your current rating for " << bookList.getBook(trueIsbn) <<
                 "=> rating:" << ratingList.getRating(memberNumber, trueIsbn)
                 << endl;
            cout << "Would you like to re-rate this book (y/n)?";
            cin >> confirm;
            if (confirm == 'y') {
                cout << "Enter your rating:";
                cin >> rating;
                if(rating == -5 || rating == -3 || rating == 0 || rating == 1 ||
                   rating == 3 || rating == 5) {
                    newRating = ratingList.changeRating(rating, memberNumber,
                                                        trueIsbn);
                    cout << "Your new rating for " << bookList.getBook(trueIsbn)
                         << "=> rating:" << newRating << endl;
                } else {
                    cout << "Please input a valid rating.";
                }
            }
        }
    } else {
        cout << "Please enter a valid ISBN number." << endl;
    }

}

void viewRating(BookList &bookList,RatingList &ratingList, MemberList
        &memberList, int memberNumber, int counterBook) {

    //Prints out all the ratings for the current member logged-in
    cout << memberList.getMember(memberNumber) << "'s ratings...\n";
    stringstream ss;
    for(int i = 0; i < counterBook; i++) {
        ss << bookList.getBook(i) << " => rating:" << ratingList.getRating
        (memberNumber, i) << endl;
    }
    cout << ss.str();
}


void displayLikes(int memberNumber, int counterBook, RatingList &ratingList,
                  MemberList &memberList, BookList &bookList) {

    //Store the member with the highest similarity
    int recommendMember = compareRating(memberNumber, counterBook,
                                        ratingList,memberList);

    //Prints out the recommender's name and the list of books that the
    // recommender recommends
    cout << endl << "You have similar taste in books as " <<
    memberList.getMember(recommendMember) << "!\n" << endl;
    displayRecommend(memberNumber, counterBook, recommendMember, ratingList,
                     memberList, bookList );


}

int compareRating(int memberNumber, int counterBook, RatingList &ratingList,
                  MemberList &memberList) {

    //Initialize certain variables
    int tempMax = 0;
    int tempIndex = 0;
    int dotProductTotal;

    //Perform the dot product comparison between current member and the others.
    for(int i = 0; i < memberList.size(); i++) {
        dotProductTotal = 0;
        if(memberNumber != i) {
            for(int j = 0; j <= counterBook; j++) {
                dotProductTotal += ratingList.getRating(i,j) *
                        ratingList.getRating(memberNumber, j);
            }

            if(dotProductTotal > tempMax) {
                tempMax = dotProductTotal;
                tempIndex = i;
            }
        }
    }
    //Return the index of the member with the highest dot product score
    return tempIndex;
}

void displayRecommend(int memberNumber, int counterBook, int recommendMember,
                      RatingList& ratingList, MemberList &memberList,
                      BookList &bookList) {

    //Displays the recommender's books
    cout << "Here are the books they really liked:" << endl << endl;

    //Book they really like needs to have a score of five and the current
    // member haven't read yet which is a score of zero
    for(int i = 0; i <= counterBook; i++) {
        int memberRating = ratingList.getRating(memberNumber, i);
        int recommender = ratingList.getRating(recommendMember, i);
        if (memberRating == 0 && recommender == 5) {
            cout << bookList.getBook(i) << endl;
        }
    }
    cout << endl << "And here are the books they liked:" << endl << endl;

    //Book they really like needs to have a score of three and the current
    // member haven't read yet which is a score of zero
    for(int i = 0; i <= counterBook; i++) {
        int memberRating = ratingList.getRating(memberNumber, i);
        int recommender = ratingList.getRating(recommendMember, i);
        if (memberRating == 0 && recommender == 3) {
            cout << bookList.getBook(i) << endl;
        }

    }
}













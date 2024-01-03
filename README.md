# Book Recommendation System

## Overview
This C++ program serves as a user interface to manage book accounts, store reviews, view those reviews, and provide book recommendations based on user preferences. It demonstrates main C++ constructs like classes, dynamic memory allocation, object state, file I/O, and public/private accessibility.



## Approach
The recommendation algorithm considers user ratings for books and calculates similarities with other users to provide personalized book recommendations.

## Classes
- `BookList`: Manages information about books in the system, including ISBN, author, title, and year.
- `MemberList`: Tracks member information, including names and unique identifiers. Also keeps track of the currently logged-in member.
- `RatingList`: Stores book ratings with values ranging from -5 to 5, reflecting the member's opinion about the books.

## Operations
- Load data from external files.
- Add new members and books.
- Login and logout functionality.
- View a user's own ratings.
- Rate books.
- Receive book recommendations.
- Quit the program.

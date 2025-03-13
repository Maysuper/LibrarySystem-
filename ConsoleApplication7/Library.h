#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

using namespace std;

// Library class to manage books
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book);
    bool borrowBook(const string& title);
    bool returnBook(const string& title);
    void reserveBook(const string& title);
    void displayBooks();
};

#endif // LIBRARY_H
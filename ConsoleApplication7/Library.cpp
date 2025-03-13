#include "Library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

bool Library::borrowBook(const string& title) {
    auto it = find_if(books.begin(), books.end(), [&title](const Book& book) { return book.getTitle() == title; });
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

bool Library::returnBook(const string& title) {
    // For simplicity, we just add the book again
    books.push_back(Book(title, "Unknown Author"));
    return true;
}

void Library::reserveBook(const string& title) {
    cout << "Book reserved: " << title << endl;
}

void Library::displayBooks() {
    cout << "Available Books:" << endl;
    for (const auto& book : books) {
        cout << book.getTitle() << " by " << book.getAuthor() << endl;
    }
}
#include "Librarian.h"
#include <iostream>

Librarian::Librarian(string id, string n, string pwd) : User(id, n, pwd) {}

void Librarian::addBook(const string& bookTitle) {
    cout << "Book added: " << bookTitle << endl;
}

void Librarian::removeBook(const string& bookTitle) {
    cout << "Book removed: " << bookTitle << endl;
}

void Librarian::displayInfo() const {
    User::displayInfo();
    cout << "Role: Librarian" << endl;
}

Librarian::~Librarian() {}
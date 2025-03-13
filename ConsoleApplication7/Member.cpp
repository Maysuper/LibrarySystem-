#include "Member.h"
#include <iostream>

Member::Member(string id, string n, string pwd) : User(id, n, pwd) {}

bool Member::borrowBook(const string& bookTitle) {
    if (borrowedBooks.size() >= maxBorrowLimit) {
        throw runtime_error("You have reached the maximum borrow limit of " + to_string(maxBorrowLimit) + " books.");
    }
    borrowedBooks.push_back(bookTitle);
    return true;
}

bool Member::returnBook(const string& bookTitle) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookTitle);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        return true;
    }
    return false;
}

void Member::displayInfo() const {
    User::displayInfo();
    cout << "Max Borrow Limit: " << maxBorrowLimit << endl;
    displayBorrowedBooks();
}

void Member::displayBorrowedBooks() const {
    cout << "Borrowed Books: ";
    for (const auto& book : borrowedBooks) {
        cout << book << " ";
    }
    cout << endl;
}

Member::~Member() {}
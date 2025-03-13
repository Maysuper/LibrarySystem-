#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <vector>
#include <stdexcept>

using namespace std;

// Member Class inherits from User
class Member : public User {
private:
    static const int maxBorrowLimit = 5;
    vector<string> borrowedBooks;

public:
    Member(string id, string n, string pwd);

    bool borrowBook(const string& bookTitle);
    bool returnBook(const string& bookTitle);

    void displayInfo() const override;
    void displayBorrowedBooks() const;
    ~Member();
};

#endif // MEMBER_H
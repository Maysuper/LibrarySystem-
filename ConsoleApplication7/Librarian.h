#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"

using namespace std;

// Librarian Class inherits from User
class Librarian : public User {
public:
    Librarian(string id, string n, string pwd);

    void addBook(const string& bookTitle);
    void removeBook(const string& bookTitle);

    void displayInfo() const override;
    ~Librarian();
};

#endif // LIBRARIAN_H

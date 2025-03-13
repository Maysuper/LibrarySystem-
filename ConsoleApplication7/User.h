#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

// Base Class: User
class User {
private:
    string userID;
    string name;
    string passwordHash;

public:
    User(string id, string n, string pwd);

    // Encapsulation - Getters
    string getUserID() const;
    string getName() const;
    string getPasswordHash() const;

    bool login(const string& password) const;

    // Polymorphism - virtual function for dynamic method dispatch
    virtual void displayInfo() const;
    virtual ~User();
};

#endif // USER_H
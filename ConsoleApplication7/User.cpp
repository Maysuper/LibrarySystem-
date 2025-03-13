#include "User.h"

User::User(string id, string n, string pwd) : userID(id), name(n), passwordHash(pwd) {}

string User::getUserID() const { return userID; }
string User::getName() const { return name; }
string User::getPasswordHash() const { return passwordHash; }

bool User::login(const string& password) const {
    return passwordHash == password;
}

void User::displayInfo() const {
    cout << "User ID: " << userID << "\nName: " << name << endl;
}

User::~User() {}

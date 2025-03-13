#include "Admin.h"
#include <iostream>

Admin::Admin(string id, string n, string pwd) : User(id, n, pwd) {}

void Admin::registerMember(const string& id, const string& name, const string& pwd) {
    cout << "New member registered: " << name << endl;
}

void Admin::registerLibrarian(const string& id, const string& name, const string& pwd) {
    cout << "New librarian registered: " << name << endl;
}

void Admin::displayInfo() const {
    User::displayInfo();
    cout << "Role: Admin" << endl;
}

Admin::~Admin() {}

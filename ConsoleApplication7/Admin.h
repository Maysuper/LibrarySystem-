#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

using namespace std;

// Admin Class inherits from User
class Admin : public User {
public:
    Admin(string id, string n, string pwd);

    void registerMember(const string& id, const string& name, const string& pwd);
    void registerLibrarian(const string& id, const string& name, const string& pwd);

    void displayInfo() const override;
    ~Admin();
};

#endif // ADMIN_H


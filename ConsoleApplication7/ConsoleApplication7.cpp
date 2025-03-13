#include <iostream>
#include <vector>
#include "User.h"
#include "Library.h"
#include "Member.h"
#include "Librarian.h"
#include "Admin.h"

using namespace std;

// Function to display the Main Menu
void DisplayMainMenu() {
    cout << "===== Smart Library Management System =====" << endl;
    cout << "1. Login as Member" << endl;
    cout << "2. Login as Librarian" << endl;
    cout << "3. Login as Administrator" << endl;
    cout << "4. Register as Member (Type 'RegisterMember')" << endl;
    cout << "5. Register as Librarian (Type 'RegisterLibrarian')" << endl;
    cout << "Type 'exit' to quit the program." << endl;
}

// Function to display the Member Menu
void MemberMenu(Member& member, Library& library) {
    int choice;
    while (true) {
        cout << "===== Member Menu =====" << endl;
        cout << "1. Borrow a Book" << endl;
        cout << "2. Return a Book" << endl;
        cout << "3. Reserve a Book" << endl;
        cout << "4. View Borrowed Books" << endl;
        cout << "5. Exit to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string bookTitle;

        try {
            if (choice == 1) {
                cout << "Enter book title to borrow: ";
                cin.ignore();
                getline(cin, bookTitle);
                if (library.borrowBook(bookTitle)) {
                    member.borrowBook(bookTitle);
                    cout << "Book borrowed successfully!" << endl;
                }
                else {
                    cout << "Book not available!" << endl;
                }
            }
            else if (choice == 2) {
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, bookTitle);
                if (member.returnBook(bookTitle)) {
                    library.returnBook(bookTitle);
                    cout << "Book returned successfully!" << endl;
                }
                else {
                    cout << "Error: Book not found in borrowed list!" << endl;
                }
            }
            else if (choice == 3) {
                cout << "Enter book title to reserve: ";
                cin.ignore();
                getline(cin, bookTitle);
                library.reserveBook(bookTitle);
            }
            else if (choice == 4) {
                member.displayBorrowedBooks();
            }
            else if (choice == 5) {
                return; // Return to main menu
            }
            else {
                cout << "Invalid choice! Try again." << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

// Function to display the Librarian Menu
void LibrarianMenu(Librarian& librarian, Library& library) {
    int choice;
    while (true) {
        cout << "===== Librarian Menu =====" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Remove a Book" << endl;
        cout << "3. View Available Books" << endl;
        cout << "4. Exit to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string bookTitle;

        if (choice == 1) {
            cout << "Enter book title to add: ";
            cin.ignore();
            getline(cin, bookTitle);
            library.addBook(Book(bookTitle, "Unknown Author"));
            cout << "Book added successfully!" << endl;
        }
        else if (choice == 2) {
            cout << "Enter book title to remove: ";
            cin.ignore();
            getline(cin, bookTitle);
            library.returnBook(bookTitle); // Assuming this would restore the book to the library for simplicity
            cout << "Book removed successfully!" << endl;
        }
        else if (choice == 3) {
            library.displayBooks();
        }
        else if (choice == 4) {
            return; // Return to main menu
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
}

int main() {
    string input;
    Admin admin("A01", "Daira", "londres");

    vector<User*> users;
    users.push_back(new Member("M01", "Maye", "exito"));
    users.push_back(new Librarian("L01", "Nata", "california"));
    users.push_back(&admin);  // Admin user

    Library library;
    library.addBook(Book("Code Complete", "Steve McConnell"));
    library.addBook(Book("Design Patterns", "Erich Gamma"));
    library.addBook(Book("The Art of Computer Programming", "Donald Knuth"));
    library.addBook(Book("Clean Code", "Robert C. Martin"));
    library.addBook(Book("Refactoring", "Martin Fowler"));
    library.addBook(Book("Check", "Mayerlin Ladino"));

    while (true) {
        DisplayMainMenu();  // Show the main menu
        cout << "Enter your choice: ";
        cin >> input;

        if (input == "exit") {
            break;
        }
        else if (input == "RegisterMember") {
            string id, name, pwd;
            cout << "Enter Member ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> pwd;
            // Add new member
            users.push_back(new Member(id, name, pwd));
            cout << "New member registered successfully!" << endl;
        }
        else if (input == "RegisterLibrarian") {
            string id, name, pwd;
            cout << "Enter Librarian ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> pwd;
            // Add new librarian
            users.push_back(new Librarian(id, name, pwd));
            cout << "New librarian registered successfully!" << endl;
        }
        else if (input == "Member" || input == "member") {
            string userID, password;
            cout << "Enter Member ID: ";
            cin >> userID;
            cout << "Enter Password: ";
            cin >> password;
            for (auto user : users) {
                if (Member* member = dynamic_cast<Member*>(user)) {
                    if (member->getUserID() == userID && member->login(password)) {
                        MemberMenu(*member, library);
                        break;
                    }
                }
            }
            cout << "Invalid Member ID or password!" << endl;  // Error message if not found
        }
        else if (input == "Librarian" || input == "librarian") {
            string userID, password;
            cout << "Enter Librarian ID: ";
            cin >> userID;
            cout << "Enter Password: ";
            cin >> password;
            for (auto user : users) {
                if (Librarian* librarian = dynamic_cast<Librarian*>(user)) {
                    if (librarian->getUserID() == userID && librarian->login(password)) {
                        LibrarianMenu(*librarian, library);
                        break;
                    }
                }
            }
            cout << "Invalid Librarian ID or password!" << endl;  // Error message if not found
        }
        else if (input == "Admin" || input == "admin") {
            string userID, password;
            cout << "Enter Admin ID: ";
            cin >> userID;
            cout << "Enter Password: ";
            cin >> password;
            if (admin.getUserID() == userID && admin.login(password)) {
                admin.displayInfo();
            }
            else {
                cout << "Invalid Admin ID or password!" << endl;  // Error message if not found
            }
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    // Cleanup dynamically allocated memory
    for (auto user : users) {
        if (user != &admin) {
            delete user;
        }
    }

    return 0;
}
#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

// Book class
class Book {
private:
    string title;
    string author;

public:
    Book(string t, string a);
    string getTitle() const;
    string getAuthor() const;
};

#endif // BOOK_H
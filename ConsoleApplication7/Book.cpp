#include "Book.h"

Book::Book(string t, string a) : title(t), author(a) {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }

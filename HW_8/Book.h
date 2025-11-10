#ifndef BOOK_H
#define BOOK_H

#include "Exercise.h"

class Book {
private:
    Exercise* first;
    Exercise* last;

public:
    Book();
    ~Book();

    Exercise* add(int c, int n);
    Exercise* get(int c, int n) const;

    void print() const;
    void assign(int c, int n);
    void unassign(int c, int n);
    void unassignChapter(int ch);
};

bool addDep(Book& B, int c1, int n1, int c2, int n2);

#endif
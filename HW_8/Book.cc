#include "Book.h"
#include <iostream>

Book::Book() : first(nullptr), last(nullptr) {}

Book::~Book() {
    for (Exercise* p = first; p;) {
        Exercise* nxt = p->next;
        delete p;
        p = nxt;
    }
}

Exercise* Book::add(int c, int n) {
    Exercise* e = new Exercise(c, n, last);
    if (!first) first = e;
    last = e;
    return e;
}

Exercise* Book::get(int c, int n) const {
    for (Exercise* p = first; p; p = p->next)
        if (p->getChap() == c && p->getNum() == n)
            return p;
    return nullptr;
}

void Book::print() const {
    int current = -1;
    for (Exercise* p = first; p; p = p->getNext()) {
        if (p->getChap() != current) {
            current = p->getChap();
            std::cout << "\nChapter " << current << '\n';
        }
        std::cout << "  ";
        p->print();
        std::cout << '\n';
    }
}

void Book::assign(int c, int n) {
    Exercise* e = get(c, n);
    if (e) e->assign();
}

void Book::unassign(int c, int n) {
    Exercise* e = get(c, n);
    if (e) e->unassign();
}

void Book::unassignChapter(int ch) {
    for (Exercise* p = first; p; p = p->getNext())
        if (p->getChap() == ch)
            p->unassign();
}

bool addDep(Book& B, int c1, int n1, int c2, int n2) {
    Exercise* a = B.get(c1, n1);
    Exercise* b = B.get(c2, n2);
    return a && b && a->addReq(b);
}
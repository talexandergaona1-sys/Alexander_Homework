#ifndef EXERCISE_H
#define EXERCISE_H

#include <array>

class Exercise {
private:
    int chap, num;
    bool assigned;
    Exercise* next;
    static const int MAX_REQ = 16;
    std::array<Exercise*, MAX_REQ> req{};
    int reqCount;

public:
    Exercise(int c, int n, Exercise* prev);
    void print() const;
    bool addReq(Exercise* e);
    void assign();
    void unassign();
    Exercise* getNext() const { return next; }
    int getChap() const { return chap; }
    int getNum() const { return num; }
    bool isAssigned() const { return assigned; }

    friend class Book;
};

#endif
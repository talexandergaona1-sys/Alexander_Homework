#include "Exercise.h"
#include <iostream>

Exercise::Exercise(int c, int n, Exercise* prev)
    : chap(c), num(n), assigned(false), next(nullptr), reqCount(0) {
    if (prev) prev->next = this;
}

void Exercise::print() const {
    std::cout << chap << '.' << num;
    if (assigned) std::cout << " [assigned]";
}

bool Exercise::addReq(Exercise* e) {
    if (!e || reqCount >= MAX_REQ) return false;
    req[reqCount++] = e;
    return true;
}

void Exercise::assign() {
    if (assigned) return;
    assigned = true;
    for (int i = 0; i < reqCount; ++i)
        req[i]->assign();
}

void Exercise::unassign() {
    assigned = false;
}
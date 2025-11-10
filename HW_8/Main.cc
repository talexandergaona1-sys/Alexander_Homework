#include "Book.h"
#include <iostream>

int main() {
    Book b;

    for (int n = 1; n <= 4; ++n) b.add(9, n);
    for (int n = 1; n <= 3; ++n) b.add(8, n);

    addDep(b, 9, 3, 9, 2);
    addDep(b, 9, 4, 8, 3);

    while (true) {
    int ch = 0, n = 0;
    std::cout << "\nEnter (chapter) (number) (0 to end): ";
    std::cin >> ch;
    if (ch == 0) break;
    std::cin >> n;

    if (n > 0) {
        b.unassignChapter(ch);
        b.assign(ch, n);
    } else {
        b.unassign(ch, -n);
    }

    b.print();
    }

    std::cout << "\nFinal Book:\n";
    b.print();
}
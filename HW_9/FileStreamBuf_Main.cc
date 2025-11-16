#include "FileStreamBuf.h"
#include <iostream>
#include <cstdio>

int main() {
    FileStreamBuf outBuf(stdout, 4);
    std::ostream out(&outBuf);

    out << "Homework 9, Program 10.3?";
    out.flush();

    std::cout << "\n";

    FileStreamBuf inBuf(stdin, 4);
    std::istream in(&inBuf);

    std::string s;
    in >> s;
    std::cout << s << "\n";

    return 0;
}
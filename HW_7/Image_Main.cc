#include "Image_Header.h"
#include <iostream>

int main() {
    Image img; // Creates image object
    img.readPPM("test.ppm");

    img += 50; // Overloads by 50

    img.writePPM("test_output.ppm");
    return 0;
}
#include "PPM_Header.h"
#include <cstdio>

int main() {
    int width, height; // W & H for image
    unsigned char* pixelData = readPPM("test.ppm", &width, &height); // Reads PPM file into array
    writePPM("test_copy.ppm", pixelData, width, height); // Writes pixel data to new file
    delete[] pixelData; // Deletes that allocated heap memory

    return 0;
}
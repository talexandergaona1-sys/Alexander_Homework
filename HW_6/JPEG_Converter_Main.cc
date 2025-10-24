#include "JPEG_Converter_Header.h"
#include <cstdio>

int main() {
    int width, height;

    // Reads pixel data from the PPM file filling the width and height & returns a pointer to the raw pixel data
    unsigned char* pixelData = readPPM("test.ppm", &width, &height);

    // Converts the raw pixel data into a JPEG file
    writeJPEG("test_output.jpg", pixelData, width, height, 90); 

    delete[] pixelData; // Deletes allocated memory
    return 0;
}
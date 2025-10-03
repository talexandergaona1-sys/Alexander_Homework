#include "mandelbrot_PPM_header.h"
#include <cstdio>

int main() {
    double minA = -2.0, maxA = 2.0; 
    double minB = -2.0, maxB = 2.0; 
    int width = 800;
    int height = 600;

    int** mandelbrotArray = new int*[height]; // Creates array of pointers
    *mandelbrotArray = new int[width * height]; // Assigns memory to array
    for (int j=1; j < height; ++j) {
        mandelbrotArray[j] = mandelbrotArray[j-1] + width; // Sets pointers to start of each row
    }

    mandelbrotSet(mandelbrotArray, width, height, minA, maxA, minB, maxB);

    unsigned char* image = mandelbrotToPic(mandelbrotArray, width, height);

    writePPM("mandelbrot_PPM_pic.ppm", image, width, height);

    delete[] *mandelbrotArray;  // Deletes flat array
    delete[] mandelbrotArray;   // Deletes array of pointers
    delete[] image;
    mandelbrotArray = nullptr;

    return 0;
}
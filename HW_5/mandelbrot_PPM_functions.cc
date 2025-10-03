#include "mandelbrot_PPM_header.h"
#include <cstdio>

double mandelbrotCalc (double a, double b) {
    double x = 0.0, y = 0.0;
    int maxIter = 1000;
    int i;

    for (i=0; i < maxIter; i++) {
        double xNext = (x * x) - (y * y) + a;
        double yNext = (2 * x * y) + b;
        x = xNext;
        y = yNext;

        if ((x * x) + (y * y) > 4) {
            return i;
        }
    }

    return maxIter;
}

// Numerical Recipe trick function
void mandelbrotSet(int** array, int width, int height, double aMin, double aMax, double bMin, double bMax) {
    for (int j=0; j < height; ++j) {
        double b = bMin + (bMax - bMin) * j / (height - 1); // Maps row values to b
        for (int i=0; i < width; ++i) {
            double a = aMin + (aMax - aMin) * i / (width - 1); // Maps column values to a
            array[j][i] = mandelbrotCalc(a, b); // Stores iterations in two dimensional array
        }
    }
}

// Flat array function
unsigned char* mandelbrotToPic(int** array, int width, int height) {
    unsigned char* pixels = new unsigned char[width * height * 3];
    int* flat = *array; // Makes two dimensional array flat

    for (int j=0; j < height; ++j) {
        for (int i=0; i < width; ++i) {
            int iter = flat[j * width +i];
            if (iter > 255) iter = 255;

            unsigned char color = (unsigned char) iter;

            int index = (j * width + i) * 3;
            pixels[index]     = color; // Holds red samples of image
            pixels[index + 1] = color; // Holds green samples of image
            pixels[index + 2] = color; // Holds blue samples of image
        }
    }

    return pixels;
}

void writePPM(const char* file, const unsigned char* data, int width, int height) {
    FILE* fp = fopen(file,"wb");
    fprintf(fp,"P6\n%d %d\n255\n", width, height);
    fwrite(data,1,width*height*3,fp);
    fclose(fp);
}
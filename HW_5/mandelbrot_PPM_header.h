#ifndef MANDELBROT_PPM_HEADER_H
#define MANDELBROT_PPM_HEADER_H

double mandelbrotCalc(double a, double b);

void mandelbrotSet(int** array, int width, int height, double aMin, double aMax, double bMin, double bMax);

unsigned char* mandelbrotToPic(int** array, int width, int height);

void writePPM(const char* file, const unsigned char* data, int width, int height);

#endif
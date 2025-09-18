#include "mandelbrot3_header.h"

void mandelbrotIter(double* x, double* y, double a, double b) { // Function using pointer arguments for iter
    double xNext = ((*x) * (*x)) - ((*y) * (*y)) + a; // Using dereferenced pointers to use actual values
    double yNext = (2 * (*x) * (*y)) + b;

    *x = xNext; // Sets new x value from dereferenced pointer
    *y = yNext; // Sets new y value from dereferenced pointer
}

double mandelbrotCalc (double a, double b) {
    double x = 0, y = 0;
    int maxIter = 1000;
    int i;

    for (i=0; i < maxIter; i++) {
        mandelbrotIter(&x, &y, a, b); // Calls new pointer function in loop

        if ((x * x) + (y * y) > 4) { 
            return i;
        }
    }

    return maxIter; 
}
#include "mandelbrot_header.h" // Links header

double mandelbrotCalc (double a, double b) {
    double x = 0, y = 0;
    int maxIter = 1000; // Likely in set after 1000 iterations
    int i;

    for (i=0; i < maxIter; i++) {
        double xNext = (x * x) - (y * y) + a;
        double yNext = (2 * x * y) + b;
        x = xNext;
        y = yNext;

        if ((x * x) + (y * y) > 4) { // Checks if values escape magnitude
            return i;
        }
    }

    return maxIter; // Value function returns to main
}

#include <iostream> // Header file library for I/O objects
#include <cmath> // Import library to use sqrt function
#include <cstdio>
using namespace std; // Lets use names for objects and variables

int main(){
    double a = .01, b = .01; // Test values to check if in set
    double x = 0, y = 0; // Initializes x & y to start at 0
    int maxIter = 500; // 500 iterations should be enough to confirm
    int i; 

    for (i=0; i < maxIter; i++) {
        double xNext = (x * x) - (y * y) + a; // Calculates next x value
        double yNext = (2 * x * y) + b; // Calculates next y value
        x = xNext; // Sets new calculated x value as x
        y = yNext; // Sets new calculated y value as y

        if (sqrt((x * x) + (y * y)) > 2) break; // If the magnitude exceeds 2 then the values are not in the set
    }
    
    // If the iterations make it to 500 they are likely in the set
    if (i == maxIter)
      printf("(%.2f, %.2f) is in the Mandelbrot set.\n", a, b);
    else
      printf("(%.2f, %.2f) is not in the Mandelbrot set.\n", a, b);

    return 0; // Ends main function  
}
#include <cstdio>
#include "mandelbrot_header.h" // Links header file

int main(){
  double minA = -2.0, maxA = 2.0; // Goes through range of values for a to check if in set
  double minB = -2.0, maxB = 2.0; // Same range check for b
  int width = 80; // Fits picture in 80 character wide window
  int height = 80; // Same character length for height
  int maxIter = 1000; // Quits calculations after 1000 iterations (likely in set)

  for (int row = 0; row < height; row++) { // Maps row to a b value from min to max, top to bottom
    double b = minB + (maxB - minB) * row / height;

    for (int col = 0; col < width; col++) { // Maps column to an a value from min to max, left to right
      double a = minA + (maxA - minA) * col / width;

      int result = mandelbrotCalc(a, b); // Calls calculation function

      if (result == maxIter) // Number is in the set so prints *
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
  return 0;
}
#include <cstdio>
#include "mandelbrot3_header.h"

int main(){
  double minA = -2.0, maxA = 2.0; 
  double minB = -2.0, maxB = 2.0; 
  int width = 80; 
  int height = 80; 
  int maxIter = 1000; 

  FILE* fp = fopen("mandelbrot_pic.txt", "w"); // Creates a new text file to write mandelbrot pic

  for (int row = 0; row < height; row++) { 
    double b = minB + (maxB - minB) * row / height;

    for (int col = 0; col < width; col++) { 
      double a = minA + (maxA - minA) * col / width;

      int result = mandelbrotCalc(a, b); 

      if (result == maxIter) 
        fprintf(fp, "*"); // File writing print function
      else
        fprintf(fp, " ");
    }
    fprintf(fp, "\n");
  }

  fclose(fp); // Closes file after writing
  return 0;
}
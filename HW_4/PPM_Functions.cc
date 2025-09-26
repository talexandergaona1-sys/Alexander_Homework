#include "PPM_Header.h"
#include <cstdio>

// Read function
unsigned char* readPPM(const char* file, int* width, int* height) {

    FILE* fp = fopen(file, "rb"); // Opens file in read binary mode

    char format[3]; // Array for P6 format (room for \0)
    fscanf(fp, "%2s", format); // Reads PPM format
    fscanf(fp, "%d %d", width, height); // Reads W & H 

    int colorVal;
    fscanf(fp, "%d", &colorVal); // Reads color value
    fgetc(fp); // Consumes \n to keep array aligned

    size_t totalBytes = (*width) * (*height) * 3; // Calculates # of bytes
    unsigned char* pixelData = new unsigned char[totalBytes]; // Allocates memory for pixel pixelData in heap (make sure to delete)
    fread(pixelData, 1, totalBytes, fp); // Reads pixel Data into array
    fclose(fp);

    return pixelData;
}

// Write function
void writePPM(const char* file, const unsigned char* pixelData, int width, int height) {

    FILE* fp = fopen(file, "wb"); // Opens file in write binary mode

    fprintf(fp, "P6\n%d %d\n255\n", width, height); // Writes PPM header
    fwrite(pixelData, 1, width * height * 3, fp); // Writes pixel Data to file
    fclose(fp);
}
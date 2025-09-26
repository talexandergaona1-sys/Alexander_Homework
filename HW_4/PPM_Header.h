#ifndef PPM_HEADER_H
#define PPM_HEADER_H

unsigned char* readPPM(const char* file, int* width, int* height);
void writePPM(const char* file, const unsigned char* data, int width, int height);

#endif
#ifndef JPEG_CONVERTER_HEADER_H
#define JPEG_CONVERTER_HEADER_H

unsigned char* readPPM(const char* filename, int* width, int* height);

void writeJPEG(const char* filename, const unsigned char* pixelData, int width, int height, int quality);

#endif
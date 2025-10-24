#include "JPEG_Converter_Header.h"
#include <cstdio>
#include <jpeglib.h>
#include <csetjmp>

// 5.4 HW function for PPM
unsigned char* readPPM(const char* file, int* width, int* height) {
    FILE* fp = fopen(file, "rb");

    char format[3];
    fscanf(fp, "%2s", format);
    fscanf(fp, "%d %d", width, height);

    int colorVal;
    fscanf(fp, "%d", &colorVal); 
    fgetc(fp);

    size_t totalBytes = (*width) * (*height) * 3;
    unsigned char* pixelData = new unsigned char[totalBytes];
    fread(pixelData, 1, totalBytes, fp);
    fclose(fp);

    return pixelData;
}

// Funciton that writes raw RGB pixel data to a JPEG file
void writeJPEG(const char* filename, const unsigned char* pixelData, int width, int height, int quality) {
    FILE* outfile = fopen(filename, "wb"); // Opens file in binary write mode.

    jpeg_compress_struct cinfo;// Compression control
    jpeg_error_mgr jerr;// Error manager

    cinfo.err = jpeg_std_error(&jerr);// Default error handling
    jpeg_create_compress(&cinfo);// Initializes JPEG compression
    jpeg_stdio_dest(&cinfo, outfile); // Sets output file as the destination

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // 3 for RGB
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo); // Loads compression parameters
    jpeg_set_quality(&cinfo, quality, TRUE);// Sets quality level
    jpeg_start_compress(&cinfo, TRUE); // Begins compression

    JSAMPROW row_pointer; // Pointer to a row of pixels
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer = (JSAMPROW)&pixelData[cinfo.next_scanline * width * 3]; // Gets address of current row
        jpeg_write_scanlines(&cinfo, &row_pointer, 1); // Writes one scanline to the JPEG file
    }

    jpeg_finish_compress(&cinfo); // Completes compression
    fclose(outfile);
    jpeg_destroy_compress(&cinfo); // Deletes allocated memory
}
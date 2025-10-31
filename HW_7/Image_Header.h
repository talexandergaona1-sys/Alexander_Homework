#ifndef IMAGE_HEADER_H
#define IMAGE_HEADER_H

#include <vector>
#include <string>

class Image {
private:
    int width;
    int height;
    std::vector<unsigned char> pixels;

public:
    Image() : width(0), height(0) {} // Constructor
    Image(int w, int h) : width(w), height(h), pixels(w * h * 3, 0) {} // Initializes size

    int getWidth() const { return width; } // Gets image width
    int getHeight() const { return height; } // Gets image height
    const std::vector<unsigned char>& getPixels() const { return pixels; } // Gets pixel data

    void readPPM(const std::string& filename);
    void writePPM(const std::string& filename) const;

    Image& operator+=(int value); // Overloader
};

#endif
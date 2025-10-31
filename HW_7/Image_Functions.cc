#include "Image_Header.h"
#include <fstream>
#include <algorithm>

void Image::readPPM(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary); // Opens file in binary mode

    std::string format;
    file >> format; // Reads PPM format

    file >> width >> height; // Reads image dimensions
    int maxVal;
    file >> maxVal;
    file.ignore(1); // Skips whitespace

    pixels.resize(width * height * 3); // Allocates space for pixels
    file.read(reinterpret_cast<char*>(pixels.data()), pixels.size()); // Reads pixel data
}

void Image::writePPM(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary); // Opens file in binary mode
    file << "P6\n" << width << " " << height << "\n255\n"; // Writes PPM header
    file.write(reinterpret_cast<const char*>(pixels.data()), pixels.size()); // Writes pixel data
}

// Overloads operator to add integer to all pixel channels
Image& Image::operator+=(int value) {
    for (auto& channel : pixels)
        channel = static_cast<unsigned char>(std::clamp(int(channel) + value, 0, 255));
    return *this;
}
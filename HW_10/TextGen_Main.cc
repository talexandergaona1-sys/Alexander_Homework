#include "Generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    const int PATTERN_LENGTH = 3; 
    const int OUTPUT_SIZE = 2000; 

    Generator gen(PATTERN_LENGTH); 

    gen.loadText("The Project Gutenberg eBook of Fran.txt");

    std::string generated = gen.generateText(OUTPUT_SIZE);

    std::cout << "Generated text:\n";
    std::cout << generated << std::endl;

    return 0;
}
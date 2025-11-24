#ifndef GENERATOR_H
#define GENERATOR_H

#include "Pattern.h"
#include <string>
#include <vector>
#include <unordered_map>

class Generator {
private:
    int length;

    std::unordered_map<std::string, int> counts; // Maps each length pattern string to its occurrence
    std::unordered_map<std::string, std::vector<Pattern> > lookup; // Maps each character prefix to all following patterns

    std::string readFile(const std::string& filename);

    void buildCounts(const std::string& text);
    void buildLookup();
    void computeProbabilities();

public:
    explicit Generator(int L);

    void loadText(const std::string& filename);
    std::string generateText(int outputSize);
};

#endif
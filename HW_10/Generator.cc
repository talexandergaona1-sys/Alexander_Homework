#include "Generator.h"
#include <fstream>
#include <cstdlib>

Generator::Generator(int L)
    : length(L) {
}

std::string Generator::readFile(const std::string& filename) {
    std::ifstream in(filename.c_str());
    std::string total;
    std::string line;

    while (std::getline(in, line)) {
        total += line; // Accumulates training text into a single string
        total += ' ';
    }
    return total;
}

void Generator::loadText(const std::string& filename) {
    std::string text = readFile(filename); 
    buildCounts(text); // Counts how many length patterns occur
    buildLookup(); // Groups patterns by their character prefix
    computeProbabilities(); // Converts counts into cumulative probabilities for each prefix
}

void Generator::buildCounts(const std::string& text) {
    int size = static_cast<int>(text.size());
    int i;

    for (i = 0; i + length <= size; ++i) {
        std::string pat = text.substr(
            static_cast<std::string::size_type>(i),
            static_cast<std::string::size_type>(length));
        ++counts[pat]; // Uses STL to increment the occurrence count for the pattern
    }
}

void Generator::buildLookup() {
    std::unordered_map<std::string, int>::iterator it;

    for (it = counts.begin(); it != counts.end(); ++it) {
        const std::string& full = it->first;
        int freq = it->second; // Uses the stored frequency for probabilities

        std::string prefix = full.substr(
            0,
            static_cast<std::string::size_type>(length - 1));
        Pattern p(full, freq); // Packs pattern string and count into a pattern object

        lookup[prefix].push_back(p);
    }
}

void Generator::computeProbabilities() {
    std::unordered_map<std::string, std::vector<Pattern> >::iterator it;

    for (it = lookup.begin(); it != lookup.end(); ++it) {
        std::vector<Pattern>& vec = it->second;

        int total = 0;
        std::size_t i;

        for (i = 0; i < vec.size(); ++i) {
            total += vec[i].getCount();
        }

        double run = 0.0;

        for (i = 0; i < vec.size(); ++i) {
            double prob = static_cast<double>(vec[i].getCount()) /
                          static_cast<double>(total);
            run += prob;
            vec[i].setCumulative(run);
        }
    }
}

std::string Generator::generateText(int outputSize) {
    std::unordered_map<std::string, std::vector<Pattern> >::iterator it =
        lookup.begin(); // Chooses a prefix from the lookup table

    std::string prefix = it->first; // Uses prefix as the starter of the generator
    std::string result = prefix;

    while (static_cast<int>(result.size()) < outputSize) {
        std::unordered_map<std::string, std::vector<Pattern> >::iterator found =
            lookup.find(prefix); // Finds all patterns that can follow the current prefix

        if (found == lookup.end()) {
            break;
        }

        double r = static_cast<double>(std::rand()) /
                   static_cast<double>(RAND_MAX);

        const std::vector<Pattern>& vec = found->second;

        const Pattern* chosen = &vec[0];
        std::size_t i;

        for (i = 0; i < vec.size(); ++i) {
            if (vec[i].getCumulative() >= r) {
                chosen = &vec[i];
                break;
            }
        }

        char nextChar = chosen->getPattern()[length - 1];
        result += nextChar;

        prefix = result.substr(
            result.size() - static_cast<std::size_t>(length - 1));
    }

    return result;
}
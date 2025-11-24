#ifndef PATTERN_H
#define PATTERN_H

#include <string>

class Pattern {
private:
    std::string pattern; // Stores length pattern from training text
    int count; // Stores how many times pattern occurs
    double cumulative; // Stores probability for random selection

public:
    Pattern(const std::string& p = std::string(), int c = 0)
        : pattern(p), count(c), cumulative(0.0) {}

    const std::string& getPattern() const {
        return pattern;
    }

    int getCount() const {
        return count;
    }

    void setCount(int c) {
        count = c;
    }

    double getCumulative() const {
        return cumulative;
    }

    void setCumulative(double value) {
        cumulative = value;
    }
};

#endif
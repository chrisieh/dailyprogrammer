#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <exception>

bool is_palindrome(const std::string &s)
{
    std::string stripped;
    std::copy_if(s.cbegin(), s.cend(), std::back_inserter(stripped),
                 [](const char &c) { return std::isalnum(c); });
    std::for_each(stripped.begin(), stripped.end(),
                  [](char &c) { c = std::tolower(c); });

    auto it = stripped.cbegin(), end = stripped.cend();
    auto r_it = stripped.crbegin();
    while (it != end) {
        if (*it != *r_it) {
            return false;
        }
        ++it;
        ++r_it;
    }
    return true;
}

void check(std::ifstream &inf) {
    std::vector<std::string> text;

    std::size_t linenum;
    std::string line;
    if (inf >> linenum && std::getline(inf, line)) {
        while (linenum != 0 && std::getline(inf, line)) {
            text.push_back(line);
            --linenum;
        }
        if (linenum != 0) {
            throw std::runtime_error("invalid input");
        }
    }
    else {
        throw std::runtime_error("invalid input");
    }

    std::string concat = std::accumulate(text.cbegin(), text.cend(), std::string());
    if (is_palindrome(concat)) {
        std::cout << "Palindrome";
    }
}


int main()
{
    std::ifstream input_1("input1.txt");
    std::ifstream input_2("input2.txt");

    std::cout << "Input 1: ";
    check(input_1);
    std::cout << std::endl;

    std::cout << "Input 2: ";
    check(input_2);
    std::cout << std::endl;

    return 0;
}

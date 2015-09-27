#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> words;
    std::string w;
    while (std::cin >> w) {
        words.push_back(w);
    }

    for (const auto &w : words) {
        if (std::is_sorted(w.cbegin(), w.cend())) {
            std::cout << w << " IN ORDER" << std::endl;
        }
        else if (std::is_sorted(w.crbegin(), w.crend())) {
            std::cout << w << " REVERSE ORDER" << std::endl;
        }
        else {
            std::cout << w << " NOT IN ORDER" << std::endl;
        }
    }

    return 0;
}

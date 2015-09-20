#include <iostream>
#include <vector>
#include <string>
#include <exception>

using state = std::vector<bool>;

state to_state(const std::string &s)
{
    state ret;

    for (const char &c : s) {
        switch (c) {
            case '0':
                ret.push_back(false);
                break;
            case '1':
                ret.push_back(true);
                break;
            default:
                throw std::runtime_error("Invalid input");
        }
    }
    return ret;
}

state next_state(const state &s)
{
    auto state_size = s.size();
    state ret;
    ret.reserve(state_size);

    if (!state_size) {
        throw std::runtime_error("empty state");
    }

    // trivial case
    if (state_size == 1) {
        ret.push_back(false);
        return ret;
    }

    // Left border
    ret.push_back(s[1] != s[state_size - 1]);

    for (std::vector<bool>::size_type i = 1; i < state_size - 1; ++i) {
        ret.push_back(s[i - 1] != s[i + 1]);
    }

    // Right border
    ret.push_back(s[state_size - 2] != s[0]);

    return ret;
}

void print_state(const state &s)
{
    for (const auto &cell : s) {
        std::cout << (cell ? 'x' : ' ');
    }
    std::cout << std::endl;
}

int main()
{
    state prev = to_state("00000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000");
    std::size_t steps = 25;

    print_state(prev);
    for (std::size_t i = 0; i < steps; ++i) {
        state curr = next_state(prev);
        print_state(curr);
        prev.swap(curr);
    }
    return 0;
}

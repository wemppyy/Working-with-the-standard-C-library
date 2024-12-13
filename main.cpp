#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evenNumbers;

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenNumbers.push_back(*it);
        }
    }

    for (auto it = evenNumbers.begin(); it != evenNumbers.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

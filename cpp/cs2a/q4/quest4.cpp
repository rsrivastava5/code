#include <iostream>
#include "Looping_Functions.h"

int main(int argc, char **argv) {
    std::cout << "First quest: " << play_game(5) << std::endl;
    std::cout << "Second quest: " << etox(2.1, 1) << std::endl << etox(3,2) << std::endl << etox(3,10) << std::endl;
    std::cout << "Third quest: " << count_chars("srivastava", 'a') << std::endl;
    size_t n1 = 1701, n2 = 3768;
    std::cout << "Fourth quest: " << "GCD of " <<  n1 << " and " << n2 << " is " << gcd(n1, n2) << std::endl;
    return 0;
}
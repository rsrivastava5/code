#include <iostream>
#include "Looping_Functions.h"

int main(int argc, char **argv) {
    std::cout << "First quest: " << play_game(5) << std::endl;
    std::cout << "Second quest: " << etox(1,10) << std::endl;
    std::cout << "Third quest: " << count_chars("srivastava", 'a') << std::endl;
    size_t n1 = 1701, n2 = 3768;
    std::cout << "Fourth quest: " << "GCD of " <<  n1 << " and " << n2 << " is " << gcd(n1, n2) << std::endl;
    n1 = 15, n2 = 50;
    std::cout << "Fourth quest: " << "GCD of " <<  n1 << " and " << n2 << " is " << gcd(n1, n2) << std::endl;
    std::cout << "Fifth quest: " << "AP terms " << get_ap_terms(-5,-3,5) << std::endl;
    std::cout << "Sixth quest: " << "GP Terms " << get_gp_terms(4, -0.5, 6) << std::endl;
    std::cout << "Seventh quest: " << "Fibonacci " << get_nth_fibonacci_number(7) << std::endl;
    return 0;
}
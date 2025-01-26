// Student ID: 20670918
//
// Looping_Functions.cpp
//

#include <iostream>
#include <sstream>

using namespace std;

// Give the user 6 chaances to guess the secret number n (0-10). If they get it,
// say so and rteurn true. Else saay so and return false.
bool play_game(int n) {
    bool rv = false;
    int num_guesses = 0;
    string user_input;
    int guess;

    cout << "Welcome to my number guessing game\n\n\n";
    for (int i = 0; i < 6; ++i) {
        cout << "Enter your guess: ";
        getline(cin, user_input);
        istringstream(user_input) >> guess;
        cout << "You entered: " << guess << endl;
        if (guess == n) {
            cout << "You found it in " << i + 1 << " guess(es)." << endl;
            return true;
        }
    }
    cout << "\nI'm sorry. You didn't find my number.\n";
    cout << "It was " << n << endl;
    return false;
}

// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term
double etox(double x, size_t n) {
    double rv = 0, temp = 1;
    for (size_t i = 0; i < n; ++i) {
        rv += temp;
        temp = temp * x / (i + 1);
    }
    return rv;
}

// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
    size_t len = s.length();
    size_t rv = 0;
    for (size_t i = 0; i < len; ++i) {
        if (s.at(i) == c) {
            ++rv;
        }
    }
    return rv;
}

// Use Euclid's algorithm to calculate the GCD of the given numbers
size_t gcd(size_t a, size_t b) {
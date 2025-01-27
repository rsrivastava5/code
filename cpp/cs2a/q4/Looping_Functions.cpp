// Student ID: 20670918
//
// Looping_Functions.cpp
//

#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

// Give the user 6 chaances to guess the secret number n (0-10). If they get it,
// say so and rteurn true. Else saay so and return false.
bool play_game(int n) {
    string user_input;
    int guess;

    cout << "Welcome to my number guessing game\n\n";
    for (int i = 0; i < 6; ++i) {
        cout << "Enter your guess: ";
        getline(cin, user_input);
        istringstream(user_input) >> guess;
        cout << "\nYou entered: " << guess << endl;
        if (guess == n) {
            cout << "You found it in " << i + 1 << " guess(es)." << endl;
            return true;
        }
    }
    cout << "I'm sorry. You didn't find my number.\n";
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
    size_t smaller = (a < b ? a : b);
    size_t larger = (a >= b ? a : b);
    size_t r = larger % smaller;

    while (r != 0) {
        larger = smaller;
        smaller = r;
        r = larger % smaller;
    }
    return smaller;
}

// Return a string of the form n1,n2,n3,... for the given AP.
string get_ap_terms(int a, int d, size_t n) {
    string rv = "";
    for (size_t i = 0; i < n; ++i) {
        stringstream ss;
        int term = a + i * d;
        ss << term;
        string temp = ss.str();
        rv += temp;
        if (i != (n-1))
            rv += ",";
    }
    return rv;
}

// Return a string of the form n1,n2,n3,... for the given GP.
string get_gp_terms(double a, double r, size_t n) {
string rv = "";
    for (size_t i = 0; i < n; ++i) {
        stringstream ss;
        double term = a * pow(r, i);
        ss << term;
        string temp = ss.str();
        rv += temp;
        if (i != (n-1))
            rv += ",";
    }
    return rv;
}

double get_nth_fibonacci_number(size_t n) {
    double term_1 = 1, term_2 = 1;
    double rv = 1;
    for (size_t i = 3; i <= n; ++i) {
        term_2 = term_1;
        term_1 = rv;
        rv = term_1 + term_2;
    }
    return rv;
}
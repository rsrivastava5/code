// Student ID: 20670918
//
// Etox.cpp
//
#include <iostream>
#include <sstream>

#include <cmath>
#include <cstdlib>

using namespace std;

double etox_5_terms(double x) {
    double rv = 1 + x + pow(x, 2) / (1 * 2) + pow(x, 3) / (1 * 2 * 3) + pow(x, 4)/(1 * 2 * 3 * 4);
    return rv;
}

int main(int argc, char **argv) {
    string user_input;
    double x;

    cout << "Enter a value for x: ";
    getline(cin, user_input);
    istringstream(user_input) >> x;
    cout << etox_5_terms(x) << endl;

    return 0;
}
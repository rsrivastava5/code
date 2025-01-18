// Student ID: 20670918
//
// Branching-Functions.cpp
//
#include <iostream>

double mean_of_3(int n1, int n2, int n3) {
    double rv = (n1 + n2 + n3)/3.0;
    return rv;
}

int max_of_5(int n1, int n2, int n3, int n4, int n5) {
    int rv = n1;
    if (rv < n2) {
        rv = n2;
    }
    if (rv < n3) {
        rv = n3;
    }
    if (rv < n4) {
        rv = n4;
    }
    if (rv < n5) {
        rv = n5;
    }
    return rv;
}

int min_of_5(int n1, int n2, int n3, int n4, int n5) {
    int rv = n1;
    if (rv > n2) {
        rv = n2;
    }
    if (rv > n3) {
        rv = n3;
    }
    if (rv > n4) {
        rv = n4;
    }
    if (rv > n5) {
        rv = n5;
    }
    return rv;
}

bool sides_make_triangle(int a, int b, int c) {
    bool rv = false;
    if (a>=0 && b>=0 && c>=0 && a+b>=c && a+c>=b && b+c>=a) {
        rv = true;
    }
    return rv;
}

bool angles_make_triangle(int A, int B, int C) {
    bool rv = false;
    if (A>=0 && B>=0 && C>=0 && (A+B+C==180)){
        rv = true;
    }
    return rv;
}

bool is_a_leap_year(int yyyy) {
    bool rv = false;
    if (yyyy % 4 == 0) {
        rv = true;
    }
    if (yyyy % 100 == 0) {
        rv = false;
    }
    if (yyyy % 400 == 0) {
        rv = true;
    }
    return rv;
}

/*
int main(int argc, char **argv) {
    std::cout << mean_of_3(1, 5, 5) << std::endl;

    std::cout << angles_make_triangle(0,0,180) << std::endl;
    std::cout << angles_make_triangle(60,60,10) << std::endl;

    std::cout << is_a_leap_year(200) << std::endl;
    std::cout << is_a_leap_year(0) << std::endl;

    return 0;
}
*/
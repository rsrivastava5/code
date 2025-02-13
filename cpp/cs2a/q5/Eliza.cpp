// Student ID: 20670918
// Eliza.cpp
// 2a.Lab-05-Eliza
//
//

#include <iostream>
#include <sstream>

using namespace std;

// Return a new string in which the letters (lowercase) a, e, i, o, and u
// have been replaced by the next vowel in the sequence aeiou. Replace u by a.
//
// Note that the string is passed in by reference. So the caller may not
// rely on the result being returned.
string rotate_vowels(string& s) {
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == 'a')
            *it = 'e';
        else if (*it == 'e')
            *it = 'i';
        else if (*it == 'i')
            *it = 'o';
        else if (*it == 'o')
            *it = 'u';
        else if (*it == 'u')
            *it = 'a';
    }
    return s;
}

// Return a string in which all occurrences of s have been replaced by th
string lispify(string s) {
    string rv = "";
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == 's')
            rv += "th";
        else if (*it == 'S')
            rv += "Th";
        else
            rv += *it;
    }
    return rv;
}

// Enter the user-interaction loop as described earlier
void enter() {
    cout << "What?" << endl;
    while(true) {
        string line;
        getline(cin, line);
        if (line == "") {
            cout << "What?" << endl;
            continue;
        }
        cout << "    " << line << endl << endl;

    }
}
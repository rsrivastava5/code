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

        size_t found = line.find('!');

        if (found != std::string::npos) {
            cout << "OMG! You don't say!! " << line << "!!!!!" << endl;
            continue;
        }

        size_t found_why = line.find("why");
        size_t found_what = line.find("what");

        if (found_why != std::string::npos || found_what != std::string::npos) {
            cout << "I'm sorry, I don't like questions that contain what or why." << endl;
            continue;
        }

        size_t found_s = line.find('s');

        if (found_s != std::string::npos) {
            cout << lispify("Interesting. When did you stop stopping your sibilans?") << endl;
            cout << lispify(line) << "! Sheesh! Now what?" << endl;
            continue;
        }

        if (line == "bye" || line == "quit" || line == "Bye" || line == "Quit") {
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        }

        int coin_toss = rand() % 10;
        if (coin_toss < 8) {
            cout << rotate_vowels(line) << "?" << endl;
        } else {
            cout << "Huh? Why do you say: " << line << "?" << endl;
        }
    }
}
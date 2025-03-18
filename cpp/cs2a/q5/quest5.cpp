#include <iostream>
#include <string>

#include "Eliza.h"

using namespace std;

int main(int argc, char **argv) {
    string s = "Sixty six";
    cout << s << " is lispified as: " << lispify(s) << endl;
    s = "that's really cool, Ursula";
    cout << s << " is rotated as: " << rotate_vowels(s) << endl;
    cout << s << endl;
    s = "";
    cout << s << " is rotated as: " << rotate_vowels(s) << endl;
    enter();
    return 0;
}
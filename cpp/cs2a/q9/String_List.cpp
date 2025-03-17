#include <iostream>
#include <fstream>

#include "String_List.h"

using namespace std;

int main() {
    string filename = "1000-most-common-words.txt";
    ifstream myfile(filename);

    if (!myfile) {
        cerr << "Can't open input file!";
        return -1;
    }

    string word;
    vector<string> word_list;

    while (getline(myfile, word)) {
        word_list.push_back(word);
    }

    cout << "Word count " << word_list.size() << endl;

    String_List string_list;
    for (int i = 0; i < 20; ++i) {
        string_list.insert_at_current(word_list[i]);
    }
    cout << string_list.to_string();

    return 0;
}
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
    for (int i = 0; i < 10; ++i) {
        string_list.insert_at_current(word_list[i]);
    }
    cout << string_list.to_string();
    string_list.push_back("Rahul");
    string_list.push_front("Srivastava");
    cout << string_list.to_string();

    cout << string_list.find_item("Srivastava") << endl;
    cout << string_list.find_item("Rahul Srivastava") << endl;

    for (int i = 0; i < string_list.get_size(); ++i) {
        cout << string_list.get_current() << endl;
        cout << string_list.advance_current() << endl;
    }

    return 0;
}
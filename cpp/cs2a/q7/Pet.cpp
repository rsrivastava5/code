// Student ID: 20670918
//
// Pet.cpp
// 2a-Lab-06-Pets
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Pet.h"

using namespace std;

// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;

Pet::Pet(string name, long id, int num_limbs) {
    _population++;
    _name = name;
    _id = id;
    _num_limbs = num_limbs;
}

Pet::~Pet() {
    _population--;
}

string Pet::get_name() const { return _name; }
long Pet::get_id() const {
    return _id;
}

int Pet::get_num_limbs() const {
    return _num_limbs;
}

bool Pet::set_name(string name) {
    if (name == "") {
        return false;
    }
    _name = name;
    return true;
}

bool Pet::set_id(long id) {
    if (id < 0) {
        return false;
    }
    _id = id;
    return true;
}

bool Pet::set_num_limbs(int num_limbs) {
    if (num_limbs < 0) {
        return false;
    }
    _num_limbs = num_limbs;
    return true;
}

string Pet::to_string() const {
    string rv("");
    string id_str, num_limbs_str;
    ostringstream oss;

    oss << _id;
    id_str = oss.str();
    oss.clear();
    oss.str("");
    oss << _num_limbs;
    num_limbs_str = oss.str();

    rv = "(Name: " + _name + ", ID: " + id_str + ", Limb Count: "
            + num_limbs_str + ")";
    return rv;
}

// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
    pets.resize(n);
    long prev_id = 0;
    for (size_t i = 0; i < n; i++) {
        long id = prev_id + 1 + rand() % 10;
        pets[i].set_id(id);
        pets[i].set_num_limbs(rand() % 9); // up to arachnids

        string name = make_a_name(name_len);
        pets[i].set_name(name);
        prev_id = id;
    }
}

// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
    const string vowels("aeiou");
    const string consonants("bcdfghjklmnpqrstvwxyz");
    string rv("");
    bool first_char_consonant = (rand() % 2 == 0 ? true : false);

    for (int i = 0; i < len; ++i) {
        if (first_char_consonant) {
            if (i % 2 == 0) {
                rv += consonants[rand() % consonants.length()];
            } else {
                rv += vowels[rand() % vowels.length()];
            }
        } else {
            if (i % 2 == 0) {
                rv += vowels[rand() % vowels.length()];
            } else {
                rv += consonants[rand() % consonants.length()];
            }
        }
    }

    return rv; 
}

// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
    if ((pet1.get_name() == pet2.get_name())
            && (pet1.get_id() == pet2.get_id())
            && (pet1.get_num_limbs() == pet2.get_num_limbs()))
        return true;
    else
        return false;
}

bool operator!=(const Pet& pet1, const Pet& pet2) {
    return !(pet1 == pet2);
}

ostream& operator<<(ostream& os, const Pet& pet) {
    return os << pet.to_string();
}

/*
int main(int argc, char **argv) {
    Pet pet;
    cout << pet << endl;

    vector<Pet> pets;
    pet.get_n_pets(10, pets, 8);
    for (int i = 0; i < pets.size(); ++i)
        cout << pets[i] << endl;

    return 0;
}
*/
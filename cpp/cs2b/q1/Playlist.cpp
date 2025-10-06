// Student ID: 20670918
//
#include "Playlist.h"

bool Playlist::Song_Entry::set_id(int id) {
    bool rv = false;
    if (id >= 0) {
        _id = id;
        rv = true;
    }
    return rv;
}

bool Playlist::Song_Entry::set_name(std::string name) {
    bool rv = false;
    if (!name.empty()) {
        _name = name;
        rv = true;
    }
    return rv;
}

int main(void) {
    Playlist::Song_Entry song(1, "Sailor");

    std::cout << song << std::endl;
    return 0;
} 
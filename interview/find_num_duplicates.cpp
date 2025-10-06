#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 50000
#define RANGE 10
#define DEBUG false

using namespace std;

size_t num_duplicates(const vector<int> &vec, int key) {
    size_t rv = 0;
    int low_idx, mid_idx;
    int high_idx;
    size_t low_found = 0;
    size_t high_found = 0;

    low_idx = 0;
    high_idx = vec.size() - 1;
    while (low_idx <= high_idx) {
        mid_idx = (low_idx + high_idx)/2;
        //cout << mid_idx << endl;
        if (vec[mid_idx] == key) {
            low_found = mid_idx;
            high_idx = mid_idx - 1;
        } else if (vec[mid_idx] < key) {
            low_idx = mid_idx + 1;
        } else {
            high_idx = mid_idx - 1;
        }
    }

    low_idx = 0;
    high_idx = vec.size() - 1;
    while (low_idx <= high_idx) {
        mid_idx = (low_idx + high_idx)/2;
        //cout << mid_idx << endl;
        if (vec[mid_idx] == key) {
            high_found = mid_idx;
            low_idx = mid_idx + 1;
        } else if (vec[mid_idx] < key) {
            low_idx = mid_idx + 1;
        } else {
            high_idx = mid_idx - 1;
        }
    }

    rv = high_found - low_found + 1;
    return rv;
}

int main(int argc, char** argv) {
    // Create a long array of ints between 0 and 10
    vector<int> vec;
    const int vec_length = MAX_SIZE;
    for (int i = 0; i < vec_length; ++i)
        vec.push_back(rand() % RANGE);
    sort(vec.begin(), vec.end());

#if DEBUG
    for (auto it = vec.begin(); it < vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
#endif

    for (int key = 0; key < RANGE; ++key)
        cout << key << " appears " << num_duplicates(vec, key) << " times." << endl;
    return 0;
}
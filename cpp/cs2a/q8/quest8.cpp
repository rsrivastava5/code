#include <iostream>

#include "Stacks.h"

using namespace std;

int main() {
    Stack_Int stack;
    int start = 0;

    for (size_t i = 0; i < 10; i++) {
        int data = start + rand() % 10;
        stack.push(data);
        start = data;
    }

    cout << stack.to_string();

    return 0;
}
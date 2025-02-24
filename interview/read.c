#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
Given API: int Read4K(char* buf);
It reads data from a file and records the position so that the next time when it is called it read the next 4k chars (or the rest of the file, whichever is smaller) from the file. The return is the number of chars read.

Todo: Use above API to Implement API
"int read(char* buf, int n)" which reads any number of chars from the file.
 */

int read4K(char *buf) {
    int rv = 0x1000;
    printf("Read %d chars\n", rv);
    return rv;
}

int read(char *buf, int n) {
    int rv = 0;
    int niter = n / 0x1000;
    int last = n % 0x1000;
    for (int i = 0; i < niter; ++i) {
        rv += read4K(buf);
        buf += 0x1000;
    }
    if (last) {
        char tmp[0x1000];
        read4K(tmp);
        memcpy(buf, tmp, last);
        rv += last;
    }

    return rv;
}

void test_case(int n) {
    printf("Requested read of %d chars\n", n);
    char *buf = malloc(n * sizeof(char));
    int temp = read(buf, n);
    printf("Copied %d chars\n", temp);
    return;
}

int main(int argc, char **argv) {
    for (int i = 0; i < 10; i++) {
        test_case((i + 1) * 0x500);
    }
}
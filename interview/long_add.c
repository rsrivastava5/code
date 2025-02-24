#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(const char *a) {
    size_t a_len = strlen(a);
    char *rv = malloc((a_len + 1) * sizeof(char));
    for (int i = 0; i < a_len; ++i) {
        rv[i] = a[a_len - 1 - i];
    }
    rv[a_len] = '\0';
    return rv;
}

char *add_strings(const char *a, const char *b) {
    char *a_rev = reverse_string(a);
    char *b_rev = reverse_string(b);
    size_t a_len = strlen(a_rev);
    size_t b_len = strlen(b_rev);
    size_t min_string = a_len < b_len ? a_len : b_len;
    size_t max_string = a_len >= b_len ? a_len : b_len;
    char *long_string = a_len >= b_len ? a_rev : b_rev;
    char *result = malloc((max_string + 2) * sizeof(char));
    unsigned int carry = 0;
    for (int i = 0; i < min_string; ++i) {
        unsigned int temp = (unsigned int)(a_rev[i] - '0') + (unsigned int)(b_rev[i] - '0') + carry;
        carry = temp / 10;
        result[i] = (char)(temp % 10 + '0');
    }
    for (int i = min_string; i < max_string; ++i) {
        unsigned int temp = (unsigned int)(long_string[i] - '0') + carry;
        carry = temp / 10;
        result[i] = (char)(temp % 10 + '0');
    }
    if (carry) {
        result[max_string] = carry + '0';
        result[max_string + 1] = '\0';
    } else {
        result[max_string] = '\0';
    }
    char *rv = reverse_string(result);
    return rv;
}

int main(int argc, char **argv) {
    char a[] = "99999999999999999999999999999999";
    char b[] = "11111111111111111111111111111111";
    printf("%s + %s = \n%s\n", a, b, add_strings(a, b));
    printf("%s + %s = %s\n", "9999", "9999", add_strings("9999", "9999"));
    printf("%s + %s = %s\n", "99", "9999", add_strings("99", "9999"));
    printf("%s + %s = %s\n", "0", "9999", add_strings("0", "9999"));
    return 0;
}
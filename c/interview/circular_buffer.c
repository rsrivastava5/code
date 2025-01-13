#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (3)

typedef struct circ_buf {
    size_t size;
    size_t read_idx;
    size_t write_idx;
    unsigned int buffer[];
} circ_buf_t;

circ_buf_t *create_buffer(size_t size) {
    circ_buf_t *rv = malloc(sizeof(circ_buf_t) + (size + 1) * sizeof(unsigned int));
    rv->read_idx = 0;
    rv->write_idx = 0;
    rv->size = size;
    return rv;
}

void delete_buffer(circ_buf_t *buf) {
    free(buf);
    return;
}

unsigned int read_val(circ_buf_t *buf) {
    unsigned int rv = (unsigned int)(-1);
    if (buf->read_idx == buf->write_idx) {
        printf("Buffer empty\n");
    } else {
        rv = buf->buffer[buf->read_idx];
        buf->read_idx = (buf->read_idx + 1) % (buf->size + 1);
    }
    return rv;
}

void write_val(circ_buf_t *buf, unsigned int val) {
    if ((buf->write_idx - buf->read_idx) % (buf->size + 1) == buf->size) {
        printf("Buffer full\n");
    } else {
        buf->buffer[buf->write_idx] = val;
        buf->write_idx = (buf->write_idx + 1) % (buf->size + 1);
    }
    return;
}

void test_case(circ_buf_t *buf, char opt, unsigned int val) {
    if (opt == 'w') {
        printf("Write %u\n", val);
        write_val(buf, val);
    } else {
        unsigned int temp = read_val(buf);
        printf("Read %u\n", temp);
    }
    printf("Read idx: %zu, Write idx: %zu\n", buf->read_idx, buf->write_idx);
    return;
}

int main()
{
    circ_buf_t* buf = create_buffer(BUFFER_SIZE);
  
    test_case(buf, 'w', 1);
    test_case(buf, 'w', 2);
    test_case(buf, 'w', 3);
    test_case(buf, 'w', 4);
    test_case(buf, 'w', 5);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'w', 6);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'w', 7);
    test_case(buf, 'r', (unsigned int)-1);
    test_case(buf, 'r', (unsigned int)-1);
    
    delete_buffer(buf);
  
    return 0;
}
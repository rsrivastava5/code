#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*******************************************
Aligned Malloc
Write an implementation of malloc() and free() that uses the underlying library functions but returns an aligned pointer. The alignment is guaranteed to be a power of 2.

Called aligned_free() on a pointer allocated by an earlier call to aligned_malloc() should free the memory.
*******************************************/
/*

malloc (32) -> 100 (0x64) -> 

*/

/* 
 * Returns an aligned pointer which is at least 'size' bytes in length.
 * size - size in bytes
 * align - alignment, guaranteed to be a power of 2
 */ 
void *aligned_malloc(size_t size, size_t align)
{
    size_t requested_alloc = size + 2 * align + sizeof(void *);
    void *temp = malloc(requested_alloc);
    void *rv;
    printf("Requested alloc: %zu\nStart Address: 0x%p\nEnd Address: 0x%p\n", requested_alloc, temp, (temp + requested_alloc - 1));
    rv = (void *)(((size_t)temp + 2 * align) & (~(align - 1)));
    printf("Returned value: %p - %p\n", rv, rv + size - 1);
    *((size_t *)rv - 1) = (size_t)temp;
    printf("Metadata location: %p\n", (size_t *)(size_t)rv - 1);
    return rv;
}
 
/*
 * Free the memory allocated by a previous call to aligned_malloc()
 */
void aligned_free(void *ptr)
{
    void *location = (void *)*((size_t *)ptr - 1);
    printf("Location being freed: %p\n", location);
    free(location); 
    return;
}


#define TEST_CASE(size, align) \
do \
{  \
  int *ptr = aligned_malloc(size, align); \
  assert(ptr && ((uintptr_t)ptr % align == 0)); \
  memset(ptr, 0, size); \
  aligned_free(ptr); \
} \
while (0)


int main()
{
  
  TEST_CASE(32, 16);
  TEST_CASE(64, 64);
  TEST_CASE(32, 8);
  TEST_CASE(64, 1024);
  
  return 0;
}

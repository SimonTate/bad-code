#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



// Can cause a segfault due to array out of bounds
uint32_t problem_function(uint32_t* ptr)
{
    return *(ptr + 5000);
}

int main (void) 
{
    uint32_t never_used = 1;
    uint32_t y[5] = { 0 };
    uint32_t *ok_ptr = malloc(sizeof(uint32_t));    
    uint32_t *no_check_ptr = malloc(sizeof(uint32_t));
    uint32_t *no_free_ptr = malloc(sizeof(uint32_t));
    uint32_t *no_alloc_ptr = NULL;

    // BAD
    printf("%d\n", y[5]);                   // 5 is out of bounds
    printf("%d\n", problem_function(y));    // problem function will go past array
    printf("%d\n", *no_alloc_ptr);          // use of ptr when it is not allocated yet 

    if(ok_ptr)
        free(ok_ptr);                       // OK. Checked before free.

    free(no_check_ptr);                     // Free without any checks that malloc returned ok
    // free(no_free_ptr);                   // Missing free.
    return INT32_MAX+1;                     // INT32 Overflow
}




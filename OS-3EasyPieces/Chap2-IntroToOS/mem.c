#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) memory address of p: %p\n", getpid(), p);
    *p = 0;
    while (1)
    {
        sleep(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p); // a4
    }
    return 0;
}

// gcc -o mem.o mem.c
//
// Only works if we disable address space randomization
// For Mac - Disable address space layout randomization (ASLR)
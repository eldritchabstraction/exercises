#include <stdio.h>

struct s {
    double f;
    int i;
    char c[3];
    void *p;
    int x[0];
};

int main(void)
{
    struct s temp;
    // HENRY: do note that the size of s is based on padding on a 64 bit arch
    printf("The size of s is %lu\n", sizeof(temp));
    printf("The size of f is %lu\n", sizeof(temp.f));
    printf("The size of i is %lu\n", sizeof(temp.i));
    printf("The size of c is %lu\n", sizeof(temp.c));
    printf("The size of p is %lu\n", sizeof(temp.p));
    printf("The size of x is %lu\n", sizeof(temp.x));
}

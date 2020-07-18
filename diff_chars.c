#include <stdio.h>

int main()
{
    //two variables, one is an array, the other is a pointer
    char a[10] = "Hello A";
    char *b = "Hello B";

    //first determine the size of these two variables
    //The size of a is 10 bytes, and the size of b depends on your system.
    //I have a 64-bit OS so my pointer size is 8 bytes
    //A 32-bit OS will have a pointer size of 4 bytes
    printf("The size of a is: %lu bytes\n", sizeof(a));
    printf("The size of b is: %lu bytes\n", sizeof(b));

    return 0;
}

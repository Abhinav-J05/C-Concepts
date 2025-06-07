#include<stdio.h>

int main(){

    // present in stack
    int x = 0;
    
    // goes in bss
    static int y = 0;

    // stored in .rodata, read only
    char *s = "Hello world";
    // s[0] = "M"; // not allowed, causing segmentation fault.
    // s is present in stack tho.

    printf("%s", s);
    y = 5;
    x = 1;

    // const only prevent modification, does not affet storage class
    // stays in stack
    const int z = 0;

    printf("Exiting main ...\n");

    return 0;
}   
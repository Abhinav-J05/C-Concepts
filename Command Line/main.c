#include<stdio.h>


int main(int argc, char* argv[])
{   // argc -> argument count (including program name)
    // argv -> array of strings (char*) representing each argument.

    printf("Total args received : %d\n", argc);
    printf("\n");
    
    for(int i=0; i<argc; i++)
    {   
        // argv[0] will always be program name, even if no args are given.
        printf("argv[%d] = %s\n", i, argv[i]);
    }


    return 0;
}
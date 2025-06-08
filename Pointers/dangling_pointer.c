#include<stdio.h>
#include<stdlib.h>


// The situation can also arise when
// address of local variable of function is returned from a function.

int *function(){

    int local = 11;

    int *ptr = &local;


    return ptr;
}

int *function2(){

    int local = 12;

    int *ptr = &local;


    return ptr;
}

int main(){

// ---------------------------------------------
//  Basic example.

    // int *ptr = malloc(1*sizeof(int));

    // *ptr = 10;
    // printf("value of ptr before : %d\n", *ptr);

    // free(ptr);

    // printf("value of ptr after : %d\n", *ptr);
    // Undefined behaviour of ptr.

// ---------------------------------------------

    int *value1 = function();

    int *value2 = function2();

    printf("value of variable returned : %d\n", *value1);
    // output came as 12.
    
    return 0;
}
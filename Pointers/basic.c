#include<stdio.h>

// Pointer is a variable.

int x = 255;

int* ptr = &x;


int* ptr1 = &x;


int **ptr_ptr = &ptr;
// pointer to pointer

void *gen = &x;

/*
* Note -
* 
* 1. Size of pointers on line 6 & 8 are same, irrespective of type of data they are pointing to.
*    Reason - size of pointer are dependent on architecture,
*             they are supposed to store 'addresses' and size
*             of addresses dependends on architecture.
*
* 2. When dereferencing ->
*    the type of the pointer tells the compiler how many bytes to read
*    and how to interpret the raw data at that memory address.
*
*
*
*
*
*/

int main()
{

    printf("Value of X : %d\n", x);
    printf("Size of X : %zu\n", sizeof(x));
    // *ptr+=1;

    printf("Value of ptr : %ld\n", ptr);
    printf("Value after dereferencing ptr : %d\n", *ptr);
    // Access the data stored at the address ptr is pointing to.
    // Interpret that data as an int (which typically occupies 4 bytes).

    // *ptr+=1;

    printf("Value of ptr1 : %ld\n", ptr1);
    printf("Value after dereferencing ptr1 : %d\n", *ptr1);
    // if x = 256, output of line 46 will be 1.
    // as 

    printf("Value after dereferencing ptr_ptr : %d\n", **ptr_ptr);

    // Size of the pointers are same, irrespective of type.
    printf("size of ptr : %zu\n", sizeof(ptr));
    printf("size of ptr1 : %zu\n", sizeof(ptr1));

    // using general pointer
    printf("Value of x using void pointer : %d\n", (int*)*ptr);


    return 0;

}
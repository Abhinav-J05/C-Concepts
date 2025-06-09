#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

void print_bytes( unsigned char *ptr, size_t size){

    for(size_t i=0; i<size; i++)
    {
        printf(" Byte %zu: 0x%02X\n", i, ptr[i]);
    }
}

typedef struct{

    uint8_t field_a;
    uint16_t field_b;
    char field_c;

} type_one;

// type one & type two only differ by order of fields.

typedef struct{

    char field_c;
    uint8_t field_a;
    uint16_t field_b;

} type_two;


typedef struct{

    uint8_t field_a;
    int *ptr1;
    int arr[10];

} type_three;

void type_three_init(type_three *structure, uint8_t value)
{
    structure->field_a = value;
    structure->ptr1 = (int*)malloc(10*sizeof(int));

    for(int i=0; i<10; i++)
    {
        structure->arr[i] = value++;
    }

    memcpy(structure->ptr1, structure->arr, 10*sizeof(int));

}


int main(){
printf("\n");
    
// ------------------------------------------------------

    type_one structure1;
    type_two structure2;
    
    structure1.field_a = 5;
    structure1.field_b = 10;
    structure1.field_c = 10;

    printf(" Size of struct 1's field a is : %zu\n", sizeof(structure1.field_a));
    printf(" Size of struct 1's field b is : %zu\n", sizeof(structure1.field_b));
    printf(" Size of struct 1's field c is : %zu\n", sizeof(structure1.field_c));

    // Size came out to be 6.
    printf(" Size of struct 1 is : %zu\n", sizeof(structure1));

    // Size came out to be 4.
    printf(" Size of struct 2 is : %zu\n", sizeof(structure2));

// ------------------------------------------------------
// Pointer in struct

    type_three structure3;

    // structure3.field_a = 5;
    // structure3.ptr1 = "abcd";

    // // Size is 32, as ptr size is 8 + 7 byte padding + 6 byte padding.
    // printf(" Size of struct 3 is : %zu\n", sizeof(structure3));
    
    type_three_init(&structure3, 10);
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", structure3.arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", structure3.ptr1[i]);
    }
    // print_bytes( (unsigned char *)&structure3, sizeof(structure3));


    printf("\n");
    return 0;
}
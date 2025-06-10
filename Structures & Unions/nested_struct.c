#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct 
{
    uint8_t field_a;
    uint8_t field_b;
    uint8_t field_c;

} nested_struct;
// Obviously needs to be defined before parent
typedef struct
{
    char name[10];
    uint8_t field_B;
    nested_struct nested1;

} parent_struct1;

typedef struct
{
    char name[10];
    uint8_t field_B;
    nested_struct *nested2;

} parent_struct2;

typedef struct
{
    char name[10];
    uint8_t field_two;
    parent_struct1 *parent_ptr;

} grand_parent_struct;





int main(){
    printf("\n");

    nested_struct child;

    parent_struct1 parent;
    parent_struct2 parent2;

    grand_parent_struct grand_parent;

    // parent.name = "Abhinav"; wrong
    strcpy(parent.name, "Abhinav");
    parent.field_B = 5;

    parent.nested1.field_a = 0;
    parent.nested1.field_b = 1;
    parent.nested1.field_c = 2;

    printf("nested1: a=%u, b=%u, c=%u\n",
           parent.nested1.field_a,
           parent.nested1.field_b,
           parent.nested1.field_c);

    // --------------------------------------------
    // Size comparison

    printf("Size of child structure %zu\n", sizeof(child));
    printf("Size of parent structure %zu\n", sizeof(parent));
    printf("Size of parent structure 2 %zu\n", sizeof(parent2));

    printf("Size of grand parent structure %zu\n", sizeof(grand_parent));


    return 0;
}

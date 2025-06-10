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

} parent_struct;




int main(){
    printf("\n");

    nested_struct child;
    parent_struct parent;

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

    return 0;
}

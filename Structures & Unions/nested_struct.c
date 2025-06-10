#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct
{
    char name[10];
    uint8_t field_B;
    nested_struct nested1;

} parent_struct;

typedef struct 
{
    uint8_t field_a;
    uint8_t field_b;
    uint8_t field_c;

} nested_struct;


int main(){
    printf("\n");

    parent_struct parent;
    nested_struct child;

    // parent.name = "Abhinav"; wrong
    strcpy(parent.name, "Abhinav");
    parent.field_B = 5;

    // parent.nested1


    return 0;
}

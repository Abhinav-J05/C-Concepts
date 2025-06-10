#include<stdio.h>
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


// pasing structure by reference
void update(parent_struct1 *P1){

    P1->field_B = 1;
    P1->nested1.field_a = 1;

    return;
};

int main(){

    parent_struct1 new_p;
    update(&new_p);
    printf(" field b - : %d",new_p.field_B);
    
    return 0;
};
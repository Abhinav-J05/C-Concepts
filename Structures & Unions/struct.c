#include<stdio.h>
#include<stdint.h>

struct first_struct {

    uint8_t field_a;
    int field_b;
} set_one = {10, 5};

/*  Memory structure of Struct 'set one;

    | uint8_t | padding | padding | padding | int   |
    |   0B    |    1B   |    2B   |    3B   | 4B-7B |
*/

// struct first_struct p1;
// p1.field_a = 10;
// p1.field_b = 5;
// Note : value assigment not valid, untill done within a function or at time of decleration.


typedef struct {
   
    int field_b;
    uint8_t field_a;
} second_struct;

second_struct set_two = {5, 10}; 

/*  Memory structure of Struct 'set one;

    | int   | uint8_t | padding | padding | padding |
    |   1-4 |    5    |   6     |    7    |    8    |

*/

/*
* Note : 
* 
* Purpose of padding -> to make sure data fields are stored at addresses,
*                       which comply with the alingment requirements.
* 
* Alignment -> compilers enforce alignment constraints to optimize performance.
*
* Scenerios -> 
* 1. When a larger data type (like int or double) follows smaller data type (like uint8_t).
* 2. At the end of the struct (to make the struct size a multiple of the largest alignment requirement).
*
* Padding avoided when -> 
* 1. Padding won't be added when the data types are naturally aligned
*    and fit perfectly without violating alignment constraints.
* 2. All fields are of the same size or the same type.
* 3. There are no misalignments between fields.
*/


typedef struct 
{
    uint8_t field_a;
    uint8_t field_b;
} third_struct;


int main(){

// --------------------------------------------------

    printf(" Field 1 of struct 1 is : %d\n", set_one.field_a);
    printf(" Field 2 of struct 1 is : %d\n", set_one.field_b);

    printf(" Size of of struct 1's field 1 is : %zu\n", sizeof(set_one.field_a));
    printf(" Size of of struct 1's field 2 is : %zu\n", sizeof(set_one.field_b));

    // size came out to be 8 bytes, even tho two fields are of 1 & 4 bytes respectively.
    // uint8
    // int
    // Size of struct = fields + padding
    printf(" Size of struct 1 is : %zu\n", sizeof(set_one));

// --------------------------------------------------
    printf("\n");
    
    printf(" Field 1 of struct 2 is : %d\n", set_two.field_a);
    printf(" Field 2 of struct 2 is : %d\n", set_two.field_b);

    printf(" Size of struct 2's field 1 is : %zu\n", sizeof(set_two.field_a));
    printf(" Size of struct 2's field 2 is : %zu\n", sizeof(set_two.field_b));

    // size came out to be 8 bytes, even tho two fields are of 4 & 1 bytes respectively.
    // int
    // uint8
    // Size of struct = fields + padding
    printf(" Size of struct 2 is : %zu\n", sizeof(set_two));

// --------------------------------------------------
    printf("\n");

    third_struct set_three;
    set_three.field_a = 1;
    set_three.field_b = 2;

    printf(" Size of struct 3's field 1 is : %zu\n", sizeof(set_three.field_a));
    printf(" Size of struct 3's field 2 is : %zu\n", sizeof(set_three.field_b));
    printf(" Size of struct 3 is : %zu\n", sizeof(set_three));


    return 0;
}
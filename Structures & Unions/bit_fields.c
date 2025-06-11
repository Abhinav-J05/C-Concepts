#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct 
{
    unsigned char modulation : 1;
    unsigned char code_rate : 2;

} Register;

/*
* Note - 
* Use of uint type is better than defining bit fields as, 
* behaviour differs and it is therefore not portable.
*/

int main () {

    Register R1;

    // multiple of 'char' size which is one byte.
    // If size increases one byte, total size of struct will become 2 bytes.
    printf("Size of struct with bit fields : %zu\n", sizeof(R1));

    return 0;
}
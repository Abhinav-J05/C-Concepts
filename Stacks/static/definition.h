#include <stdlib.h>
#include <stdint.h>


#define MAX 10

// static stack
typedef struct {

    int data[MAX];
    int top;
} Stack;
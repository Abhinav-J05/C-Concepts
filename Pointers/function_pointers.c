#include<stdio.h>
#include<stdlib.h>

/*
* Note -
*
* Use of function pointer - 
* 1. Callbacks
*     Allow functions to be passed as arguments to other functions. 
*       
* 2. Dynamic function dispath
*    
*/

// ------------------------------------------------
// Callback implementation

void greet(char *name)
{
    printf("Hello %s !\n", name);

}

// function is expecting a pointer to a function as first argument.
void function(void (*callback)(char*), char *name)
{
    callback(name);
}

int main()
{
    function(greet, "Abhinav");

    return 0;
}
#include <stdbool.h>

#include "definition.h"

/*
* 1. Initialisation function
* 
* 2. Empty check
*
* 3. Capacity check
*
* 4. Push
*
* 5. Pop
*
* 6. Peek
* 
*/



// 1.
void stack_init(Stack* stack)
{
    stack->top = -1;
}

// 2.
bool is_empty(Stack* stack)
{
    return stack->top == -1;
}

// 3.
bool is_full(Stack* stack)
{
    return stack->top == MAX - 1;
}

// 4.
bool push_op(Stack* stack, int dat)
{
    // check
    if(!is_full(stack))
    {
        stack->data[++(stack->top)] = dat;
        return true;
    }

    return false;
}

// 5. 
int pop_op(Stack* stack)
{
    // check
    if(!is_empty(stack))
    {
        return stack->data[(stack->top)--];
    }

    return -1;
}

// 6.
int peek_op(Stack* stack)
{
    // check
    if(!is_empty(stack))
    {
        return stack->data[stack->top];
    }

    return -1;
}

void printStack(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->data[i]);
    }
    
    printf("\n");
}
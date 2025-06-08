#include<stdio.h>
#include<stdlib.h>


typedef int(* arithmetic)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}


int main()
{
    arithmetic operation;

    int a = 5, b = 10;
    int choice = -1;

    printf("Choose an operation:\n1. Add\n2. Subtract\n3. Multiply\n");
    scanf("%d", &choice); 

    switch (choice) {
        case 1:
            operation = add;  
            break;
        case 2:
            operation = subtract;  
            break;
        case 3:
            operation = multiply;  
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }


    printf("Result: %d\n", operation(a, b));

    return 0;
}


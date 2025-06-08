#include <stdio.h>
#include <stdlib.h>


/*
* Note - Both in static and dynamic allocation,
*        the memory blocks are contiguous, 
*        therefore pointer arithmetic works exactly the same way in both cases.
*/

int main(){

// -----------------------------------------------
    // Dynamic
    int *p1 = (int *)malloc(5 * sizeof(int));
    
    // P1 points to first byte of allocated block.
    // p1+1 will 'move' the pointer to next byte.

    for (int i = 0; i < 5; i++) {
        *(p1 + i) = i + 1;  // p + i is like arr[i]
    }

    printf("First element: %d\n",  *p1);           
    printf("Second element: %d\n", *(p1 + 1)); 
    printf("Third element: %d\n",  *(p1 + 2));  
    printf("Fourth element: %d\n", *(p1 + 3)); 
    printf("Fifth element: %d\n",  *(p1 + 4));  


    *(p1 + 2) = 10; // Change the third element (index 2) to 10

    printf("Modified third element: %d\n", *(p1 + 2)); 

    free(p1);

// ----------------------------------------------
    printf("\n");

    int arr[5] = {1, 2, 3, 4, 5};
    
    int *p2 = arr;  
    // p2 points to the first element of arr
    // p2 = &arr[0];


    printf("First element: %d\n", *(&arr[0]));       
    printf("First element: %d\n", *p2);       
    
    printf("Second element: %d\n", *(p2 + 1));
    printf("Third element: %d\n", *(p2 + 2)); 

    // Modifying elements using pointer arithmetic
    *(p2 + 3) = 10;

    printf("Modified Fourth element: %d\n", arr[3]); // Output: 10



    return 0;
}

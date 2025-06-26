#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/* -----------------------------------------------------------
* The idea of jump search is ..
* 
* array -> [1,2,3,4,5,6,7,8,9]
* total size of array is = 9
* 
* Choose block size :
* step = floor(root(n)) which is in this case, 3.
*
* Jump over array with step size of 3
*
* Assuming target is 7 - 
*  
* a[2] = 3 → too small
*
* a[5] = 6 → still small
*
* a[8] = 9 → too big! Target must be between a[6] and a[8]
* now do a linear search between a[6] and a[8].
*
*/ 

#define min(a,b) ((a) < (b) ? a : b )

int search(int* arr, int arrSize, int target)
{
    int step = sqrt(arrSize);
    int prev = 0;

    while(arr[min(step, arrSize) - 1] < target)
    {
        prev = step;
        step += (int)sqrt(arrSize);
        if (prev >= arrSize)
            return -1;
    }

     for (int i = prev; i < min(step, arrSize); i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}



int main(int argc, char* argv[])
{
    char* endpoint;

    int target = strtol(argv[1], &endpoint, 10);
    
    if (*endpoint != '\0') {
        printf("Invalid target: %s\n", argv[1]);
        return 1;
    }

    int arrSize = strtol(argv[2], &endpoint, 10);
    
    if (*endpoint != '\0' || arrSize <= 0) {
        printf("Invalid size: %s\n", argv[2]);
        return 1;
    }

    // create space
    int* arr = malloc(arrSize* sizeof(int));



    // fill the array
    for(int i = 0; i< arrSize; i++)
    {
        int num = strtol(argv[i+3], &endpoint, 10);
        
        if (*endpoint != '\0')
        {
            printf("Invalid integer: %s\n", argv[i+3]);
            return 1;
        }
        arr[i] = num;
    }

    int index = search(arr, arrSize, target);

    if(index != -1)
    {
        printf(" Target index found : %d\n", index);
    }
    else
    {
        printf(" Target not found ... \n");
    }

    free(arr);
    return 0;
}
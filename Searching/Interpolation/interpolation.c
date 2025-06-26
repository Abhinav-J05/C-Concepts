#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int search(int* arr, int arrSize, int target)
{   
    int low = 0;
    int high = arrSize - 1;

    // base condition
    
    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        if(arr[high] - arr[low] == 0)
            break;
        
        int ind = low + (int)(((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));

        if(arr[ind] == target)
        {
            return ind;
        }
        else if(arr[ind] < target)
        {
            low = ind + 1;
        }
        else if(arr[ind] > target)
        {
            high = ind - 1;
        }

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
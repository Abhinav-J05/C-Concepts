#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct Package
{
    uint8_t serial_no;
    uint8_t date;

    struct Package* next;
} Package;

void update(Package *P1){

    P1->date = 1;
    P1->serial_no = 0;

    // P1->next->serial_no = 0;
    Package* current = P1;

    while(current != NULL)
    {
        current->serial_no = 5;
        current = current->next;
    }

    return;
};

int main()
{

    Package* first = malloc(sizeof(Package)); 
    Package* second = malloc(sizeof(Package));

    first->serial_no = 1;
    first->date = 1;
    first->next = second;

    second->serial_no = 2;
    second->date = 2;
    second->next = NULL;

    Package* current = first;

    update(current);

    while(current != NULL)
    {
        printf("Current is at %d\n", current->serial_no);

        current = current->next;
    }
    

    return 0;
}
#ifndef UNIT_H
#define UNIT_H

#include <time.h>
#include <stdbool.h>


#define MAX_NAME_LEN 256


typedef enum
{
    FILE,
    DIRECTORY,
} unit_type;


typedef struct unit_t unit;
// Each unit structure
struct unit_t
{
    char name[MAX_NAME_LEN];                // Name of file or directory
    unit_type type;                         // Whether file or directory

    time_t creation_time;                   // Time of creation
    time_t modification_time;               // Last modified

    char* content;                          // Content of file
    size_t size;                            // Size of content

    bool is_hidden;                         // Hidden file flag
    bool is_readonly;                       // Read only file

    struct unit_t* parent;                  // Current's parent
    struct unit_t* child;                   // Current's child 
    struct unit_t* next_silbling;           // Current's next sibling

    unsigned int ID;                        // Unique ID

};





#endif
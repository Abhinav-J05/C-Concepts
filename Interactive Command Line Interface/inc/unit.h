#ifndef UNIT_H
#define UNIT_H

#include <time.h>
#include <stdbool.h>


#define MAX_NAME_LEN 256
#define MAX_PATH_LEN 256


typedef enum
{
    IS_FILE,
    IS_DIRECTORY,
} unit_type_t;


typedef struct unit unit_t;
// Each unit structure
struct unit
{
    char name[MAX_NAME_LEN];                // Name of file or directory
    unit_type_t type;                       // Whether file or directory

    time_t creation_time;                   // Time of creation
    time_t modification_time;               // Last modified

    char* content;                          // Content of file
    size_t size;                            // Size of content

    bool is_hidden;                         // Hidden file flag
    bool is_readonly;                       // Read only file

    struct unit* parent;                    // Current's parent
    struct unit* child;                     // Current's child 
    struct unit* next_silbling;             // Current's next sibling

    unsigned int ID;                        // Unique ID

};

typedef struct {

    unit_t* path[MAX_PATH_LEN];               // Stack of directories from root to current
    int depth;                              // Depth in the file tree

} session_state_t;


#endif
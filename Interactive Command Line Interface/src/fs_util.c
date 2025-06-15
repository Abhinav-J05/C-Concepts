#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fs_util.h"


static unsigned int GLOBAL_UNIT_ID = 0;



//  File creation
unit_t* create_file(session_state_t curr_state, bool is_hidden, bool is_readonly, char* file_name, char* content)
{
    unit_t* curr_dir = curr_state.path[curr_state.depth];
    // Safety

    if (curr_dir->type != IS_DIRECTORY)
    {
        show_error("Cannot create file inside another file!");
        return NULL;
    }
    
    unit_t* fresh_unit = (unit_t*)malloc(1* sizeof(unit_t));
    if (!fresh_unit)
    {
        show_error("Memory allocation failed!");
        return NULL;
    }

    // Set meta data
    strncpy(fresh_unit->name, file_name, MAX_NAME_LEN);
    fresh_unit->name[MAX_NAME_LEN - 1] = '\0';

    fresh_unit->type                = IS_FILE;
    fresh_unit->creation_time       = time(NULL);
    fresh_unit->modification_time   = fresh_unit->creation_time;

    fresh_unit->is_hidden           = is_hidden;
    fresh_unit->is_readonly         = is_readonly;
    fresh_unit->parent              = curr_dir;
    fresh_unit->child               = NULL;
    fresh_unit->next_sibling        = NULL;

    // Copy Content
    if (content)
    {
        fresh_unit->size = strlen(content);
        fresh_unit->content = (char*)malloc(fresh_unit->size + 1);
        if (!fresh_unit->content)
        {
            show_error("Memory allocation failed for file content!");
            free(fresh_unit);
            return NULL;
        }
        strcpy(fresh_unit->content, content);
    }
    else
    {
        fresh_unit->content = NULL;
        fresh_unit->size = 0;
    }

    // Set parent and sibling pointers
    fresh_unit->parent              = curr_dir;
    fresh_unit->next_sibling        = NULL;
    fresh_unit->prev_sibling        = NULL;
    fresh_unit->child               = NULL;

    if (curr_dir->child == NULL)
    {
        curr_dir->child = fresh_unit;
    }
    else
    {
        unit_t* last = curr_dir->child;
        while (last->next_sibling != NULL)
        {
            last = last->next_sibling;
        }
        last->next_sibling = fresh_unit;
        fresh_unit->prev_sibling = last;
    }

    // Unique ID
    fresh_unit->ID = GLOBAL_UNIT_ID++;

    return fresh_unit;

}



// Dir creation
unit_t* create_dir(session_state_t curr_dir, const char* dir_name, bool is_hidden)
{
    // validate curr_dir

    // make dir & allocate mem

    // set meta data

    // attach to tree

    // return created dir

}
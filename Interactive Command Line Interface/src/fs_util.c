#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#include "fs_util.h"





//  File creation
unit_t* create_file(session_state_t curr_dir, bool is_hidden, bool is_readonly, char* file_name, char* content)
{
    // check if curr_dir is dir/file

    // create file & allocate memory for content

    // Set meta data
        // creation time
        // modification time
        // type = file
        // ID - global/static counter

    // attach file to the tree

    // return the created file

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
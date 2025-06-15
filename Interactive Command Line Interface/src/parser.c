#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "unit.h"
#include "fs_util.h"
#include "cli_util.h"

int process_input(const char* input, session_state_t state)
{
    while(1)
    {

        // create a file
        if(strncmp(input, "touch ", 6) == 0)
        {   
            // TODO : decouple traverse logic to target path & file creation logic from here.
            // char *args = input + 6;

            // // Split into filename and content
            // char *filename = strtok(args, " ");
            // char *file_content = strtok(NULL, "");

            // if (filename == NULL)
            // {
            //     show_error("Filename missing for touch command.");
            //     continue;
            // }

            // if (file_content == NULL)
            //     file_content = ""; 

            create_file(target_dir, false, false, filename, file_content);
            continue;
        }

        if(strncmp(input, "cd ", 3) == 0)
        {
            switch_session_state(&state, input + 3);
            continue;
        }

        else
        {
            show_error("Invalid command !");
            return 1;
        }
    }

    return 1;
}
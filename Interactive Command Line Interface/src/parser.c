#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "unit.h"
#include "cli_util.h"

int process_input(const char* input, session_state_t state)
{
    while(1)
    {
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "unit.h"
#include "cli_util.h"



#define MAX_INPUT_LEN 60


int session_open()
{   
    static session_state_t state;
    char user_input[MAX_INPUT_LEN];
    char prompt[300];
    
    // Welcome
    printf("\033[1;34m╭──────────────────────────────────────╮\n"         );
    printf(          "│            SESSION STARTED           │\n"         );
    printf(          "╰──────────────────────────────────────╯\033[0m\n\n");

    
    while(1)
    {

        // generate prompt
        generate_prompt(&state, prompt, sizeof(prompt));
        printf("%s", prompt);
        fflush(stdout);

        if(fgets(user_input, MAX_INPUT_LEN, stdin) == NULL)
            break;  

        // refine
        user_input[strcspn(user_input, "\n")] = 0;
            
        if (strlen(user_input) == 0)
            continue;

        if (strcmp(user_input, "exit") == 0)
        {
            char confirm;
            printf("\033[1;33mAre you sure you want to exit? [Y/N]: \033[0m");
            confirm = getchar();
            getchar(); // consume the leftover newline character from input buffer

            if (confirm == 'Y' || confirm == 'y')
            {
                printf("\033[1;33mExiting session...\033[0m\n");
                break;
            }
            else
            {
                printf("\033[1;34mExit canceled.\033[0m\n");
                continue;
            }
        }

        if(strcmp(user_input, "clear") == 0)
        {
            // clear_screen();
            continue;
        }

        if(strcmp(user_input, "reset") == 0)
        {
            reset_session_state();
            continue;
        }

        if(strcmp(user_input, "save") == 0)
        {
            // save_session();
            continue;
        }

        if(strcmp(user_input, "load") == 0)
        {
            // load_session();
            continue;
        }

        if(strcmp(user_input, "grep") == 0)
        {

        }

        if(strcmp(user_input, "help") == 0)
        {
            // show_help();
            continue;
        }


        int ret = process_input(user_input, &state);

    }
    
    printf("\033[1;34m╭──────────────────────────────────────╮\n"         );
    printf(          "│            SESSION CLOSED            │\n"         );
    printf(          "╰──────────────────────────────────────╯\033[0m\n\n");
}




// ==== Main Entry ====
int main()
{
    session_open();
    return 0;
}
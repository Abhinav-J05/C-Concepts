#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#include "cli_util.h"


void reset_session_state()
{

}

void switch_session_state(session_state_t* state, char* dest_add)
{


}

void inform_success(const char *message)
{
    if (message)
    {
        printf("\033[1;32m[Success] %s\033[0m\n", message);
    }
}

void show_error(const char *message)
{
    if (message)
    {
        printf("\033[1;31m[ERROR] %s\033[0m\n", message);
    }
}

void generate_prompt(const session_state_t *state, char *prompt_out, size_t maxlen)
{

    if (state == NULL || prompt_out == NULL || maxlen == 0)
        return;

    // Case: root
    if (state->depth == 0)
    {
        snprintf(prompt_out, maxlen, "\033[1;34m# \033[1;34m");
        return;
    }

    // Start the prompt with green color and opening bracket
    int written = snprintf(prompt_out, maxlen, "\033[1;34m[");
    size_t used = (written < 0) ? 0 : (size_t)written;

    for (int i = 0; i < state->depth; ++i)
    {
        const char *name = state->path[i]->name;
        size_t name_len = strlen(name);

        // Ensure enough space for name, delimiter, and closing part
        if (used + name_len + 5 >= maxlen)
            break;

        strncat(prompt_out, name, maxlen - used - 1);
        used += strlen(name);

        if (i < state->depth - 1)
        {
            strncat(prompt_out, "➜", maxlen - used - 1);
            used += 1;
        }
    }

    // Close prompt
    strncat(prompt_out, "]# \033[1;34m", maxlen - strlen(prompt_out) - 1);
}

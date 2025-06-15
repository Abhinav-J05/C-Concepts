/* 
* -------------------------------------------------------------------
* 
* File        : cli_util.h
* Author      : Abhinav Joshi
* 
* Description : Utility function declarations for command line interface.
* 
* Usage       : Include this header in modules that require utility 
*               routines such as path operations.
* 
* License     : MIT
* 
* -------------------------------------------------------------------
*/

#ifndef CLI_UTIL_H
#define CLI_UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cli_util.h"
#include "unit.h"


/**
 * @brief Clears the terminal screen using ANSI escape codes.
 * 
 */
void clear_screen();

/**
 * @brief Prints success message in color coding.
 * 
 */
void inform_success(const char *message);

/**
 * @brief Prints error message in color coding.
 * 
 */
void show_error(const char *message);

/**
 * @brief Handles exit confirmation from the user.
 * 
 * @return true if the user chooses to exit, false otherwise.
 */
bool exit_confirmation();


// Reset session state
void reset_session_state();

void switch_session_state();


/**
 * @brief Generates the dynamic CLI prompt string based on the current session state.
 * 
 */
void generate_prompt(const session_state_t *state, char *prompt_out, size_t maxlen);


#endif
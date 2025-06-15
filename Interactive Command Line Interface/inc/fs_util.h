/* 
* -------------------------------------------------------------------
* 
* File        : fs_util.h
* Author      : Abhinav Joshi
* 
* Description : Utility function declarations for file system.
* 
* Usage       : Include this header in modules that require utility 
*               routines such as file creation and
*               directory creation.
* 
* License     : MIT
* 
* -------------------------------------------------------------------
*/

#ifndef FS_UTIL_H
#define FS_UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cli_util.h"
#include "unit.h"


/**
 * @brief Creates a new file unit in the current directory.
 * 
 * @param curr_dir     The current session state representing the working directory path stack.
 * @param is_hidden    Flag indicating whether the file should be hidden.
 * @param is_readonly  Flag indicating whether the file should be read-only.
 * @param file_name    Name of the file to be created (must be unique within the directory).
 * @param content      Optional content to write at the time of file creation. Can be NULL.
 * 
 * @return Pointer to the newly created file unit on success, or NULL on failure (e.g., invalid parent, duplicate name).
 */
unit_t* create_file(session_state_t curr_dir, bool is_hidden, bool is_readonly, char* file_name, char* content);

/**
 * @brief Creates a new directory under the current working directory.
 * 
 * @param curr_dir     The current session state representing the working directory path stack.
 * @param dir_name     Name of the new directory to be created.
 * @param is_hidden    Flag indicating whether the directory should be hidden.
 * 
 * @return Pointer to the newly created directory unit on success, or NULL on failure (e.g., invalid parent, duplicate name).
 */
unit_t* create_dir(session_state_t curr_dir, const char* dir_name, bool is_hidden);






#endif
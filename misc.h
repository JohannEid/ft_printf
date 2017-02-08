//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_MISC_H
#define PRINTF_PROJECT_MISC_H

#include <unistd.h>
#include "dynamic_array.h"
#include <zconf.h>
#include <limits.h>


void ft_printf( char * to_print, ...);
void format_output(char variable_type, va_list argument_list);
void convert_a_string(s_array * array, const char * string_to_conv);
void convert_to_character(s_array * array,int ascii_code);
void convert_to_string (s_array * array, int num_to_convert);
void string_reverse (s_array *to_reverse);
void screen_output (char * to_output, size_t bits);




#endif //PRINTF_PROJECT_MISC_H

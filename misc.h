//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_MISC_H
#define PRINTF_PROJECT_MISC_H

#include <unistd.h>
#include "dynamic_array.h"


void ft_printf( char * to_print, ...);
void format_output(char variable_type, va_list argument_list);
s_array convert_to_string (int num_to_convert);
void string_reverse (s_array *to_reverse);



#endif //PRINTF_PROJECT_MISC_H

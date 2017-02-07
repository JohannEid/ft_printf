//
// Created by johann on 04/02/17.
//

#include <zconf.h>
#include "misc.h"



void ft_printf(char *to_print, ...) {
    //varialbe argument initialisation
    va_list argument_list;
    va_start(argument_list,to_print);
    //loop variable
    int i = 0;
    //initialise our dynamic array to story char into it
    s_array char_array;
    init_array(&char_array, 1);
    //char conversion
    //check if there is formating


    while (to_print[i] != '\0') {
        if (to_print[i] != '%') {

            insert_in_array(&char_array, to_print[i]);

            //1 bit = 1 char so ok to write

        } else if (to_print[i] == '%') {
            if (write(1, char_array.array, char_array.used) != char_array.used)
                _exit(0);
           format_output(to_print[++i], argument_list);
            //we initialise again our array
            free_array(&char_array);
            init_array(&char_array, 1);
        }
        ++i;
        if (to_print[i] == '\0') {
            if (write(1, char_array.array, char_array.used) != char_array.used)
                _exit(0);
        }
    }


    free_array(&char_array);
    va_end(argument_list);
}


void format_output(char variable_type, va_list argument_list) {
    switch (variable_type) {
        case 'd':
            break;
    }
}








/*
const size_t size_of_string(const char *to_size) {
    size_t counter = 0;
    while (to_size[counter] != '\0') {
        ++counter;
    }
    return counter;
}
*/


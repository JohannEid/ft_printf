//
// Created by johann on 04/02/17.
//

#include <zconf.h>
#include "misc.h"

void ft_printf(char *to_print, ...) {
    //varialbe argument initialisation
    //va_list argument_list;
    //va_start(to_print,argument_list);
    //loop variable
    int i = 0;
    //initialise our dynamic array to story char into it
    s_array char_array;
    init_array(&char_array, 1);
    //char conversion
    char to_convert = ' ';


    while (to_print[i] != '\0') {
        if (to_print[i] != '%') {

            insert_in_array(&char_array, to_print[i]);
            if (write(1, char_array.array, char_array.used) != char_array.used)
                _exit(0);
            //1 bit = 1 char so ok to write

        } else if (to_print[i] == '%') {
            to_convert = to_print[++i];
            //we initialise again our array
            printf("yo");

            free_array(&char_array);
            init_array(&char_array, 1);
        }

        ++i;

    }
    free_array(&char_array);
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


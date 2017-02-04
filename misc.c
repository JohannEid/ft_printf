//
// Created by johann on 04/02/17.
//

#include <zconf.h>
#include "misc.h"

void ft_printf(const char *to_print, ...) {

    char error_msg[] = "There was an error in the output of the function";
    size_t size_of_print = size_of_string(to_print);
    size_t size_of_error = size_of_string(error_msg);
    va_list list_of_variables;
    va_start(list_of_variables, to_print);


    search_for_expression(to_print);
    if (write(1, to_print, size_of_print) != size_of_print) {
        write(2, error_msg, size_of_error);
    }

}

const size_t size_of_string(const char *to_size) {
    size_t counter = 0;
    while (to_size[counter] != '\0') {
        ++counter;
    }
    return counter;
}


void search_for_expression(const char *to_search) {
    s_array  my_array;

    init_array(&my_array,1);



    int counter = 0;
    while (to_search[counter] != '\0')
    {
        ++counter;
        if(to_search[counter] == '%'){}
    }



}

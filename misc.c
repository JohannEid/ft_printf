//
// Created by johann on 04/02/17.
//

#include "misc.h"


void ft_printf(const char* to_print,...) {
    char error_msg [] = "There was an error in the output of the function";

//    search_for_expression(to_print);
    if (write(1, to_print , size_of_string(to_print)) != size_of_string(to_print)){
        write(2, error_msg,size_of_string(error_msg));
    }

}

 const size_t  size_of_string(const char * to_size) {
     size_t i = 0;
    while (to_size[i] != '\0')
    {
        ++i;
    }
    return i;
}

//void search_for_expression()

//
// Created by johann on 04/02/17.
//

#include "misc.h"


void ft_printf(char *to_print, ...) {
    //varialbe argument initialisation
    va_list argument_list;
    va_start(argument_list, to_print);
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
            screen_output(char_array.array, char_array.used);
            format_output(to_print[++i], argument_list);
            //we initialise again our array
            free_array(&char_array);
            init_array(&char_array, 1);
        }
        ++i;
        if (to_print[i] == '\0') {
            screen_output(char_array.array, char_array.used);
        }
    }


    free_array(&char_array);
    va_end(argument_list);
}


void format_output(char variable_type, va_list argument_list) {
    s_array array;
    init_array(&array,1);
    switch (variable_type) {
        case 'd':
        case 'i':
            convert_to_string(&array,va_arg(argument_list, int));
            break;

            /*
        case 'c':
            screen_output(va_arg(argument_list,char), sizeof(char));
            break;
        case 's':
            screen_output (va_arg(argument_list, char*), sizeof(char*));
            break;
             */

    }
    screen_output(array.array,array.used);
    free_array(&array);
}

//int find_num_of_digits()

void convert_to_string(s_array* array, int num_to_convert) {
    char digit;
    if (num_to_convert == 0) {
        insert_in_array(array, '0');
    } else if (num_to_convert < 0) {
        insert_in_array(array, '-');
        num_to_convert *= -1;
    }
    while (num_to_convert > 0) {
        digit = num_to_convert % 10 + '0';
        insert_in_array(array, digit);
        num_to_convert /= 10;
    }
    string_reverse(array);
}

void string_reverse(s_array *to_reverse) {
    if (to_reverse->used == 0)
        return;
    char copy;

    int i = (to_reverse->array[0] == '-') ? 1 : 0;
    int j = to_reverse->used - 1;

    while (i <= j) {
        copy = to_reverse->array[i];
        to_reverse->array[i] = to_reverse->array[j];
        to_reverse->array[j] = copy;
        ++i;
        --j;
    }
}

void screen_output(char *to_output, size_t bits) {
    const char *msg_error = "Error detected";
    if (write(1, to_output, bits) != bits) {
        (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error));
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


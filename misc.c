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
    switch (variable_type) {
        case 'd':
        case 'i':
            screen_output(convert_to_string(va_arg(argument_list, int)).array, sizeof(int));
            break;
    }
}

s_array convert_to_string(int num_to_convert) {
    s_array array;
    init_array(&array, 1);
    char digit;
    if (num_to_convert == 0) {
        insert_in_array(&array, '0');
    } else if (num_to_convert < 0) {
        insert_in_array(&array, '-');
        num_to_convert *= -1;
    }
    while (num_to_convert > 0) {
        digit = num_to_convert % 10 + '0';
        insert_in_array(&array, digit);
        num_to_convert /= 10;
    }
    string_reverse(&array);
    return array;
}

void string_reverse(s_array *to_reverse) {
    if (to_reverse->used == 0)
        return;
    char copy;

    int i = to_reverse->array[0] == '-' ? 1 : 0;
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
    if (write(1, to_output, t_bits) != t_bits) {
        (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error));
        exit(-1);
    }
    exit(0);

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


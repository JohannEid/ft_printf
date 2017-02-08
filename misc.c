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
    init_array(&array, 1);
    switch (variable_type) {
        case 'u':
            convert_to_string(&array, va_arg(argument_list, int), FALSE);
        case 'd':
        case 'i':
            convert_to_string(&array, va_arg(argument_list, int), TRUE);
            break;
        case 'c':
            //not forced to use array but code is cleaner ... :)
            convert_to_character(&array, va_arg(argument_list, int));
            break;
        case 's':
            convert_a_string(&array, va_arg(argument_list, const char *));
            break;

    }
    screen_output(array.array, array.used);
    free_array(&array);
}

//int find_num_of_digits()

void convert_to_string(s_array *array, int num_to_convert, int is_signed) {
    char digit;
    const char msg_error[] = "Ungisned format expected but received signed \n";

    if (num_to_convert == 0) {
        insert_in_array(array, '0');
    } else if (num_to_convert < 0) {
        if (!is_signed) {
            write(2, msg_error, sizeof(msg_error));
            return;}
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

void convert_a_string(s_array *array, const char *string_to_conv) {
    int i = 0;
    while (string_to_conv[i] != '\0') {
        insert_in_array(array, string_to_conv[i]);
        ++i;
    }
}


void convert_to_character(s_array *array, int num_to_convert) {
    const char msg_error [] = "Error detected";
    char c;
    if ((num_to_convert < 128) && (num_to_convert >= 0)) { c = num_to_convert; }
    else { (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error)); }
    insert_in_array(array, c);
}


void screen_output(char *to_output, size_t bits) {
    const char msg_error [] = "Error detected";
    if (write(1, to_output, bits) != bits) {
        (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error));
    }
}

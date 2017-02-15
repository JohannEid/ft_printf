//
// Created by johann on 04/02/17.
//

#include "misc.h"


void ft_printf(char *to_print, ...) {
    //varialbe argument initialisation
    va_list argument_list;
    //loop variable
    int i = 0;
    //initialise our dynamic array to story char into it
    s_array char_array;
    //char conversion
    //check digits precicision
    s_array digits_before_point;
    s_array digits_after_point;
    int point_reached = FALSE;

    init_array(&char_array, 1);
    init_array(&digits_before_point, 1);
    init_array(&digits_after_point, 1);
    va_start(argument_list, to_print);


    while (to_print[i] != '\0') {
        if (to_print[i] != '%') {
            insert_in_array(&char_array, to_print[i]);
            //1 bit = 1 char so ok to write
        } else if (to_print[i] == '%') {
            screen_output(char_array.array, char_array.used);
            ++i;
            while (isdigit(to_print[i]) || (to_print[i] == '.')) {
                if (to_print[i] == '.') {
                    point_reached++;
                } else if (isdigit(to_print[i])) {
                    (!point_reached) ? insert_in_array(&digits_before_point, to_print[i]) :
                    insert_in_array(&digits_after_point, to_print[i]);
                }

                if (point_reached > 1) { break; }
                ++i;
            }
            format_output(to_print[i], argument_list, &digits_before_point, &digits_after_point);
            //we initialise again our array
            point_reached = 0;
            reinitialise_array(&char_array);
            reinitialise_array(&digits_before_point);
            reinitialise_array(&digits_after_point);
        }
        ++i;
        if (to_print[i] == '\0') {
            screen_output(char_array.array, char_array.used);
        }
    }
    free_array(&char_array);
    free_array(&digits_before_point);
    free_array(&digits_after_point);
    va_end(argument_list);
}


void format_output(char variable_type, va_list argument_list,
                   s_array *digits_before_point, s_array *digits_after_point) {
    const char *string_argument;
    s_array array;
    init_array(&array, 1);
    //for precision of string and float
    //for string before point will be min width for float num of integet before coma
    //after will max width for string and number of digit after coma for float
    int before_point = convert_string_to_int(digits_before_point);
    int after_point = convert_string_to_int(digits_after_point);
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
            string_argument = va_arg(argument_list, const char *);
            add_spaces(&array, before_point - array.used);
            convert_a_string(&array, string_argument);
            cut_string(&array, len_of(string_argument) - after_point);
            break;
        case 'f':
            convert_float_to_string(&array, va_arg(argument_list, double), after_point,before_point);
            break;

    }
    screen_output(array.array, array.used);
    free_array(&array);
}

//int find_num_of_digits()

void convert_to_string(s_array *array, int num_to_convert, int is_signed) {
    char digit;
    int compteur = 0;
    const char msg_error[] = "Ungisned format expected but received signed \n";

    if (num_to_convert == 0) {
        insert_in_array(array, '0');
    } else if (num_to_convert < 0) {
        if (is_signed) {
            insert_in_array(array, '-');
        }
        num_to_convert *= -1;
    }
    while (num_to_convert > 0) {
        digit = num_to_convert % 10 + '0';
        array->array[compteur] == ' ' ? array->array[compteur] = digit : insert_in_array(array, digit);
        num_to_convert /= 10;
        ++compteur;
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
    int difference = array->used - len_of(string_to_conv);
    //lengh of string bigger then spaces we have we start at start of array
    if (difference < 0) {
        for (int i = 0; i < len_of(string_to_conv); ++i) {
            if (i >= array->used) { insert_in_array(array, string_to_conv[i]); }
            else {
                array->array[i] = string_to_conv[i];
            }
        }
    } else if (difference >= 0) {

        for (int j = 0; j < len_of(string_to_conv); ++j) {
            array->array[difference] = string_to_conv[j];
            ++difference;
        }
    }
}


void convert_to_character(s_array *array, int num_to_convert) {
    const char msg_error[] = "Error detected";
    char c;
    if ((num_to_convert < 128) && (num_to_convert >= 0)) { c = num_to_convert; }
    else { (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error)); }
    insert_in_array(array, c);
}


void screen_output(char *to_output, size_t bits) {
    const char msg_error[] = "Error detected";
    if (write(1, to_output, bits) != bits) {
        (write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error));
    }
}


int convert_string_to_int(s_array *array_to_convert) {
    int value = 0;
    if (array_to_convert->used == 0) { return 0; }

    for (int i = 0; i < array_to_convert->used; ++i) {
        value += (array_to_convert->array[i] - 48) * power(10, array_to_convert->used - 1 - i);
    }
    return value;
}

void add_spaces(s_array *array_to_add_spaces, int number_of_spaces) {

    if (number_of_spaces <= 0) { return; }
    for (int i = 0; i < number_of_spaces; ++i) {
        insert_in_array(array_to_add_spaces, ' ');
    }
}

int power(int value, int power) {
    int initial_value = value;
    if (power == 1) { return value; }
    else if (power == 0) { return 1; }
    for (int i = 1; i < power; ++i) {
        value *= initial_value;
    }
    return value;
}

void cut_string(s_array *array_to_cut, int number_to_cut) {

    if (number_to_cut <= 0) { return; }
    //no memory leak they will just not be printed but memory will free them nonetheless
    array_to_cut->used -= number_to_cut;

}

int len_of(const char *array) {
    size_t i = 0;
    while (array[i] != '\0') {
        ++i;
    }
    return i;
}

void convert_float_to_string(s_array *array, double to_convert, int precision, int width_precision) {
    s_array array_decimal;
    int integer = (int) to_convert;
    double floating_num = to_convert - integer;
    int decimal;
    init_array(&array_decimal, 1);

    decimal = (precision == 0) ? floating_num * power(10, 6) :
              floating_num * power(10, precision);

    add_spaces(array,width_precision);
    convert_to_string(array, integer, TRUE);
    insert_in_array(array, '.');
    convert_to_string(&array_decimal, decimal, FALSE);
    concatenate(array, &array_decimal);
    free_array(&array_decimal);
}

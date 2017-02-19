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
    int power_of_ten = 0;
    double scien_notation = 0;
    switch (variable_type) {
        case 'u':
            convert_to_string(&array, va_arg(argument_list, unsigned
                    int), TRUE);
            break;
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
            add_char(&array, before_point - array.used, ' ');
            convert_a_string(&array, string_argument);
            cut_string(&array, len_of(string_argument) - after_point);
            break;

        case 'e':
        case 'E':
        case 'f':

            scien_notation = va_arg(argument_list, double);
            power_of_ten = (variable_type != 'f')?
                            get_scientific_notation(&scien_notation):number_of_zeros(&scien_notation);
            convert_float_to_string(&array, scien_notation, after_point, before_point, power_of_ten);
            (variable_type != 'f')?  add_power_of_ten_precision(&array, power_of_ten, variable_type) : ' ';
            break;
        case 'o':
            convert_to_octal_or_dec(&array, va_arg(argument_list, unsigned
                    int), TRUE);
            break;
        case 'x':
        case 'X':
            convert_to_octal_or_dec(&array, va_arg(argument_list, unsigned
                    int), FALSE);
            break;
    }
    screen_output(array.array, array.used);
    free_array(&array);
}


void convert_to_string(s_array *array, int num_to_convert, int is_signed) {
    char digit;
    int compteur = 0;
    unsigned int unumber_to_conv;

    if (num_to_convert == 0) {
        insert_in_array(array, '0');
        return;
    } else if (num_to_convert < -0.0) {
        if (is_signed) {
            insert_in_array(array, '-');
        }
        num_to_convert *= -1;
    }
    //convert_uint_to_string(array,unumber_to_conv);

    //doesn 't see the zeros in decimal numbers SAD !
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

void add_char(s_array *array_to_add, int width, char to_add) {
    if (width <= 0) { return; }
    for (int i = 0; i < width; ++i) {
        insert_in_array(array_to_add, to_add);
    }
}

double power(double value, int power) {
    double initial_value = value;
    int initial_power = power;
    (power < 0) ? power *= -1 : power;

    if (initial_power == 1) { return value; }
    else if (power == 0) { return 1; }

    for (int i = 1; i < power; ++i) {
        value *= initial_value;
    }

    value = (initial_power < 0) ? 1 / value : value;
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

void convert_float_to_string(s_array *array, double to_convert, int precision, int width_precision,
                             int zero_add) {
    s_array array_decimal;
    int integer = (int) to_convert;
    double floating_num = to_convert - integer;
    int decimal;
    init_array(&array_decimal, 1);

    decimal = (precision == 0) ? floating_num * power(10, 6) :
              floating_num * power(10, precision);

    add_char(array, width_precision, ' ');


    convert_to_string(array, integer, TRUE);
    insert_in_array(array, '.');
    /*
    if (zero_add < 0) {
        zero_add *= -1;
        add_char(array, zero_add - 1 , '0');
    }
     */

    convert_to_string(&array_decimal, decimal, FALSE);
    concatenate(array, &array_decimal);
    free_array(&array_decimal);
}


void convert_to_octal_or_dec(s_array *array, unsigned int to_convert, int is_octal) {
    char rest = '0';
    int quotient = to_convert;
    unsigned int result = 0;
    int compteur = 0;
    int div = (is_octal) ? 8 : 16;

    while (quotient >= div) {
        rest = quotient % div;
        quotient = (quotient - rest) / div;
        (is_octal) ? result += rest * power(10, compteur) : insert_in_array(array, match_int_to_char(rest));
        ++compteur;
    }
    if (is_octal) {
        result += quotient * power(10, compteur);
        convert_to_string(array, result, TRUE);
    } else {
        rest = quotient;
        insert_in_array(array, match_int_to_char(rest));
        string_reverse(array);
    }
}

char match_int_to_char(char to_match) {

    switch (to_match) {
        case 10:
            to_match = 'A';
            break;
        case 11:
            to_match = 'B';
            break;
        case 12:
            to_match = 'C';
            break;
        case 13:
            to_match = 'D';
            break;
        case 14:
            to_match = 'E';
            break;
        case 15:
            to_match = 'F';
            break;
        default:
            to_match += '0';
            break;
    }
    return to_match;
}

void add_power_of_ten_precision(s_array *array, int power_of_ten, char var) {
    char to_insert;

    insert_in_array(array, var);
    if (power_of_ten < 0) {
        insert_in_array(array, '-');
        power_of_ten *= -1;
    } else if (power_of_ten >= 0) { insert_in_array(array, '+'); }
    to_insert = power_of_ten + '0';

    if (power_of_ten <= 9) {
        insert_in_array(array, '0');
        insert_in_array(array, to_insert);
    } else if (power_of_ten > 9) { insert_in_array(array, to_insert); }
}

int get_scientific_notation(double *to_get_power) {
    int compteur = 0;
    double multiple_of_10 = 10;
    double temp;
    //numbers starting by 0.000
    temp = (*to_get_power < 0) ? -(*to_get_power) : *to_get_power;
    if (temp >= 1) {
        multiple_of_10 = 10;
        while (temp > multiple_of_10) {
            ++compteur;
            multiple_of_10 *= 10;
        }
    } else if (temp < 1) { compteur = number_of_zeros(to_get_power); }

    *to_get_power *= power(10, -compteur);

    return compteur;
}

int number_of_zeros(double *to_get_zeros) {
    double temp = (*to_get_zeros < 0) ? -(*to_get_zeros) : *to_get_zeros;
    double multiple_of_10 = 0.1;
    int compteur = 0;


    while (temp <= multiple_of_10) {
        multiple_of_10 *= 0.1;
        ++compteur;
    }
    return -(compteur + 1);
}




/*
void convert_uint_to_string (s_array* array , unsigned int  num_to_convert) {
int compteur = 0;
    char digit;

    while (num_to_convert > 0) {
        digit = num_to_convert % 10 + '0';
        array->array[compteur] == ' ' ? array->array[compteur] = digit : insert_in_array(array, digit);
        insert_in_array(array, digit);
        num_to_convert /= 10;
        ++compteur;
    }
    string_reverse(array);

}

*/
//
// Created by johann on 04/02/17.
//

#include "misc.h"


void ft_printf(char *to_print, ...) {
    //varialbe argument initialisation
    va_list argument_list;
    //loop variable
    int i = 0;
    char my_flags[5] = {'-', '+', ' ', '#', '0',};
    //initialise our dynamic array to story char into it
    s_array char_array;
    s_array flag_array;
    //char conversion
    //check digits precicision
    s_array digits_before_point;
    s_array digits_after_point;
    int point_reached = FALSE;

    init_array(&char_array, 1);
    init_array(&digits_before_point, 1);
    init_array(&digits_after_point, 1);
    init_array(&flag_array, 1);
    va_start(argument_list, to_print);


    while (to_print[i] != '\0') {
        if (to_print[i] != '%') {
            insert_in_array(&char_array, to_print[i]);
            //1 bit = 1 char so ok to write
        } else if ((to_print[i] == '%') && (to_print[i + 1] == '%')) { ++i; }
        else if (to_print[i] == '%') {
            screen_output(char_array.array, char_array.used);
            ++i;
            while (check_in(to_print[i], my_flags, 5)) {
                insert_in_array(&flag_array, to_print[i]);
                ++i;
            }
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
            format_output(to_print[i], argument_list, &digits_before_point, &digits_after_point,
                          &flag_array);
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
                   s_array *digits_before_point, s_array *digits_after_point, s_array *flags) {
    const char *string_argument;
    s_array array;
    init_array(&array, 1);
    //for precision of string and float
    //for string before point will be min width for float num of integet before coma
    //after will max width for string and number of digit after coma for float
    int before_point = convert_string_to_int(digits_before_point);
    int after_point = convert_string_to_int(digits_after_point);
    double scien_notation = 0;
    switch (variable_type) {
        case 'u':
            unsigned_int_formating(&array, flags, va_arg(argument_list, unsigned
                    int), before_point);
            break;
        case 'd':
        case 'i':
            int_formating(&array, flags, va_arg(argument_list, int), before_point);
            break;
        case 'c':
            //not forced to use array but code is cleaner ... :)
            convert_to_character(&array, va_arg(argument_list, int));
            break;
        case 's':
            convert_a_string(&array, va_arg(argument_list, const char *), before_point, after_point);
            break;

        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            float_formating(&array, flags, va_arg(argument_list, double), variable_type, after_point,
                            before_point);
            break;
        case 'o':
        case 'x':
        case 'X':
            hexa_octa_formating(&array, flags, va_arg(argument_list, unsigned
                    int), variable_type, before_point);
            break;
    }
    screen_output(array.array, array.used);
    free_array(&array);
}


void convert_to_string(s_array *array, int num_to_convert, int is_signed, int width) {
    char digit;
    int compteur = 0;
    unsigned int unumber_to_conv;
    s_array buffer_array;

    init_array(&buffer_array, 1);

    if (num_to_convert == 0) {
        insert_in_array(&buffer_array, '0');
    } else if (num_to_convert < -0.0) {
        if (is_signed) {
            insert_in_array(&buffer_array, '-');
        }
        num_to_convert *= -1;
    }

    while (num_to_convert > 0) {
        digit = num_to_convert % 10 + '0';
        insert_in_array(&buffer_array, digit);
        num_to_convert /= 10;
        ++compteur;
    }
    string_reverse(&buffer_array);
    width -= buffer_array.used;
    add_char(array, width - 1, ' ');

    concatenate(array, &buffer_array);
    free_array(&buffer_array);
}

void string_reverse(s_array *to_reverse) {
    if (to_reverse->used == 0)
        return;
    char copy;

    int i = (to_reverse->array[1] == 'X') ? 2 : (to_reverse->array[1] == 'x') ? 2 :
                                                (isdigit(to_reverse->array[0])) ? 0 : 1;
    int j = to_reverse->used - 1;

    while (i <= j) {
        copy = to_reverse->array[i];
        to_reverse->array[i] = to_reverse->array[j];
        to_reverse->array[j] = copy;
        ++i;
        --j;
    }
    (to_reverse->array[0] == '#') ? to_reverse->array[0] = '0' : ' ';
}

void convert_a_string(s_array *array, const char *string_to_conv, int before_point, int after_point) {
    int difference = array->used - len_of(string_to_conv);
    //lengh of string bigger then spaces we have we start at start of array

    (before_point != 0) ? add_char(array, before_point - array->used, ' ') : ' ';
    if (difference < 0) {
        for (int i = 0; i < len_of(string_to_conv); ++i) {
            if (i >= array->used) {
                insert_in_array(array, string_to_conv[i]);
            } else {
                array->array[i] = string_to_conv[i];
            }
        }
    } else if (difference > 0) {

        for (int j = 0; j < len_of(string_to_conv); ++j) {
            array->array[difference] = string_to_conv[j];
            ++difference;
        }
    }
    (before_point != 0) ? cut_string(array, len_of(string_to_conv) - after_point) : ' ';

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
    if (width < 0) { return; }
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

    if (number_to_cut < 0) { return; }
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
                             char variable_type) {
    int spaces;
    int integer;
    double floating_num;
    int decimal;
    int power_of_ten;

    power_of_ten = get_power_of_ten(to_convert);
  if(variable_type !='f'){to_convert = get_scientific_notation(to_convert, power_of_ten);}


    integer = (int) to_convert;
    floating_num = to_convert - integer;
    decimal = (precision == 0) ? floating_num * power(10, 6) :
              floating_num * power(10, precision);
    precision = (precision == 0) ? 6 : precision;
    convert_to_string(array, integer, TRUE, width_precision - precision);
    insert_in_array(array, '.');
    if ((power_of_ten < 0) & (variable_type == 'f') && (integer == 0)) {
        add_char(array, (power_of_ten * -1 - 1), '0');
    }
    convert_to_string(array, decimal, FALSE, 0);
    (decimal == 0) ? add_char(array, precision - 1, '0') : ' ';
    (variable_type != 'f') ? add_power_of_ten_precision(array, power_of_ten, variable_type) : ' ';
}

// maybe I should have made a function for each but process so similar seems like a waste ..
void convert_to_octal_or_dec(s_array *array, unsigned int to_convert, int is_octal, int width) {
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
        if (array->array[0] == '#') { array->array[0] = '0'; }
        convert_to_string(array, result, TRUE, width);
    } else {
        rest = quotient;
        insert_in_array(array, match_int_to_char(rest));
        string_reverse(array);
    }
}

char match_int_to_char(char to_match) {
    char tab_char[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    if ((int) to_match < 10) { return to_match + '0'; }

    return tab_char[(int) to_match % 10];
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


double get_scientific_notation(double to_get_power,int power_of_ten) {

    return to_get_power * power(10,-power_of_ten);
}


int get_power_of_ten(double to_get_power) {
    int compteur = 0;
    double multiple_of_10;

    if (to_get_power < 1) {
        multiple_of_10 = 0.1;
        while (to_get_power < multiple_of_10) {
            multiple_of_10 *= 0.1;
            ++compteur;
        }
        return -(compteur + 1);
    } else if (to_get_power >= 1) {
        multiple_of_10 = 10;
        while (to_get_power > multiple_of_10) {
            multiple_of_10 *= 10;
            ++compteur;
        }
        return compteur;
    }

}

int check_in(char to_check, char tab_check[], int size_of_tab) {
    if (size_of_tab == 0) { return 0; }
    for (int i = 0; i < size_of_tab; ++i) {
        if (tab_check[i] == to_check) { return 1; }
    }
    return 0;
}

void unsigned_int_formating(s_array *text_array, s_array *flags, unsigned int uint, int width) {
    const char msg_error[] = "Error unsigned int can't be signed ...\n ";

    flag_insertion(text_array, flags, uint, 'u');
    convert_to_string(text_array, uint, TRUE, width);
    if (text_array->array[0] == '-') {
        write(2, msg_error, sizeof(msg_error)) != sizeof(msg_error);
    }
    flag_insertion_end(text_array, flags, uint, 'u');

}

void int_formating(s_array *text_array, s_array *flags, int my_int, int width) {

    flag_insertion(text_array, flags, my_int, 'd');
    convert_to_string(text_array, my_int, TRUE, width);
    flag_insertion_end(text_array, flags, my_int, 'd');

}

void float_formating(s_array *text_array, s_array *flags, double my_double, char var_arg,
                     int after_point, int before_point) {
    char temp;
    if ((var_arg == 'g') || (var_arg == 'G')) {
        temp = 'f';
    } else { temp = var_arg; }
    flag_insertion(text_array, flags, my_double, var_arg);
    convert_float_to_string(text_array, my_double, after_point, before_point, temp);
    if ((var_arg == 'g') || (var_arg == 'G')) {
        if (!check_in('#', flags->array, flags->used)) {
            suppress_trailing_zeros(text_array);
        } else { text_array->used -= 1; }
    }
    flag_insertion_end(text_array, flags, my_double, var_arg);


    free_array(flags);

}

void hexa_octa_formating(s_array *text_array, s_array *flags, unsigned int to_convert, char var_arg, int width) {
    int is_octa = FALSE;
    is_octa = (var_arg == 'o') ? TRUE : FALSE;
    flag_insertion(text_array, flags, to_convert, var_arg);
    convert_to_octal_or_dec(text_array, to_convert, is_octa, width);
    flag_insertion_end(text_array, flags, to_convert, var_arg);

}

void flag_insertion_end(s_array *text_array, s_array *flags, double flag_conditions, char type_format) {
    char number_types[] = {'d', 'i', 'X', 'x', 'u', 'f', 'e', 'E', 'g', 'G'};

    if ((check_in(type_format, number_types, 10)) &&
        (check_in('0', flags->array, flags->used))) {
        fill_blank_space(text_array);
    }
}

void flag_insertion(s_array *text_array, s_array *flags, double flag_conditions, char type_format) {

    if ((type_format != 'X') && (type_format != 'x') && (type_format != 'o')) {
        if (check_in('+', flags->array, flags->used) && (flag_conditions >= 0)) {
            insert_in_array(text_array, '+');
        } else if (check_in(' ', flags->array, flags->used)) {
            insert_in_array(text_array, '_');
        }
    }

    if (check_in('#', flags->array, flags->used)) {
        if (type_format == 'o') {
            insert_in_array(text_array, '#');
        } else if ((type_format == 'X') || (type_format == 'x')) {
            insert_in_array(text_array, '0');
            insert_in_array(text_array, type_format);
        }
    }
}

void suppress_trailing_zeros(s_array *text_array) {
    int trailing_zeros = 0;
    int counter;
    if (!is_decimal(text_array->array)) { return; }
    if (text_array->array[text_array->used - 1] != '0') { return; }
    counter = text_array->used - 1;
    while ((text_array->array[counter] == '0') || (text_array->array[counter] == '.')) {

        ++trailing_zeros;
        if (text_array->array[counter] == '.') {
            break;
        }
        --counter;

    }
    text_array->used -= trailing_zeros;
}

int is_decimal(char *array_of_char) {
    for (int i = 0; i < len_of(array_of_char); ++i) {
        if (array_of_char[i] == '.') { return TRUE; }
    }
    return FALSE;

}

void fill_blank_space(s_array *text_array) {
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < text_array->used; ++i) {
        if (check_in(text_array->array[i], digits, 10)) { break; }
        (text_array->array[i] == ' ') ? text_array->array[i] = '0' : ' ';
    }
}

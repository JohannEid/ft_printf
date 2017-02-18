//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_MISC_H
#define PRINTF_PROJECT_MISC_H

#include <unistd.h>
#include "dynamic_array.h"
#include <zconf.h>
#include <limits.h>

#define FALSE 0
#define TRUE !(FALSE)


void ft_printf(char *to_print, ...);

void format_output(char variable_type, va_list argument_list,
                   s_array *digits_before_point, s_array *digits_after_point);

void convert_a_string(s_array *array, const char *string_to_conv);

void convert_to_character(s_array *array, int ascii_code);

void convert_to_string(s_array *array, int num_to_convert, int is_signed);

int convert_string_to_int(s_array  *array_to_convert);

int power (int value , int power);

void string_reverse(s_array *to_reverse);

void screen_output(char *to_output, size_t bits);

void add_spaces (s_array *array_to_add_spaces, int number_of_spaces);

void cut_string (s_array* array_to_cut,int number_to_cut);

int len_of (const char *array);

void convert_float_to_string(s_array *array,  double to_convert, int precision,int width_precision);

void convert_to_octal_or_dec (s_array *array, unsigned int to_convert,int is_octal);

char  match_int_to_char (char to_match);

void add_power_of_ten_precision (s_array *array);

//void replace

//void convert_uint_to_string (s_array* array , unsigned int  number_to_convert);





#endif //PRINTF_PROJECT_MISC_H

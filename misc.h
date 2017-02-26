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
                   s_array *digits_before_point, s_array *digits_after_point,s_array *flags);

void convert_a_string(s_array *array, const char *string_to_conv, int before_point, int after_point,
s_array *flags);

void convert_to_character(s_array *array, int ascii_code);

void convert_to_string(s_array *array, int num_to_convert, int is_signed,int width);

int convert_string_to_int(s_array *array_to_convert);

double power(double value, int power);

void string_reverse(s_array *to_reverse);

void screen_output(char *to_output, size_t bits);

void add_char(s_array *array_to_add_spaces, int number_of_spaces, char to_add);

void cut_string(s_array *array_to_cut, int number_to_cut);

int len_of(const char *array);

void convert_float_to_string(s_array *array, double to_convert, int precision, int width_precision,
                             char variabe_type);

void convert_to_octal_or_hexa(s_array *array, unsigned int to_convert, int is_octal,int width, int is_upper);

char match_int_to_char(char to_match,int is_upper);

void add_power_of_ten_precision(s_array *array, int power_of_ten, char var);

double get_scientific_notation(double to_get_power,int power_of_ten);
//for decimal numbers
int number_of_zeros(double to_get_zeros);

int check_in (char to_check,   char tab_check[], int size_of_tab);

void unsigned_int_formating (s_array *text_array, s_array *flags, unsigned int uint,int width);

void int_formating (s_array *text_array, s_array *flags, int my_int,int width);

void float_formating(s_array *text_array, s_array *flags, double my_double, char var_arg, int after_point,
int before_point);

void hexa_octa_formating (s_array *text_array,s_array *flags, unsigned int to_convert,char var_arg,int width);

void flag_insertion(s_array *text_array, s_array *flags,double flag_conditions,char type_format);

void flag_insertion_end(s_array *text_array, s_array *flags,double flag_conditions,char type_format);


void suppress_trailing_zeros(s_array *text_array);

int is_decimal(char *array_of_char);

void fill_blank_space(s_array *text_array);

int get_power_of_ten(double to_get_power);

char lower(char to_lower);

void handle_g_float_precision(s_array *text_array,int precision);

void relocate_sign(s_array *text_array);

int is_signed(s_array *text_array);



//void replace

//void convert_uint_to_string (s_array* array , unsigned int  number_to_convert);





#endif //PRINTF_PROJECT_MISC_H

//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_MISC_H
#define PRINTF_PROJECT_MISC_H

#include <unistd.h>
#include "dynamic_array.h"
#include "node.h"


void ft_printf(const char *, ...);

s_node *create_list(const char *);

const size_t size_of_string(const char *);


#endif //PRINTF_PROJECT_MISC_H

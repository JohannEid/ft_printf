//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_NODE_H
#define PRINTF_PROJECT_NODE_H

#include "dynamic_array.h"

typedef struct t_node{
    s_array data;
    struct t_node * next;
}s_node;

void add_node (s_node * head, s_array  data);
#endif //PRINTF_PROJECT_NODE_H

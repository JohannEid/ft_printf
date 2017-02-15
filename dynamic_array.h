//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_DYNAMIC_ARRAY_H
#define PRINTF_PROJECT_DYNAMIC_ARRAY_H

#include <glob.h>
#include <malloc.h>


typedef struct t_array {
    char *array;
    size_t used;
    size_t size;

}s_array;


void init_array( s_array * array_to_init , size_t initial_size);
void insert_in_array (s_array * array_to_insert , char to_insert );
void free_array (s_array * array_to_free );
void reinitialise_array(s_array * to_reint);
void concatenate (s_array *left , s_array *right);



#endif //PRINTF_PROJECT_DYNAMIC_ARRAY_H

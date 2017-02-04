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

void init_array( s_array *, size_t );
void insert_in_array (s_array * , char );
void free_array (s_array * );



#endif //PRINTF_PROJECT_DYNAMIC_ARRAY_H

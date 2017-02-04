//
// Created by johann on 04/02/17.
//

#include <glob.h>
#include <malloc.h>
#include "my_struct.h"

struct t_array {
    char *array;
    size_t used;
    size_t size;

};

void init_array(s_array *my_array, size_t initial_size) {
    my_array->array = (char *) malloc(initial_size * sizeof(char));
    my_array->used = 0;
    my_array->size = initial_size;

}

void insert_in_array(s_array *my_array, char element) {
    // if we don't have any more room then we multiply size by 2 and realloc
    if (my_array->used == my_array->size) {
        my_array->size *= 2;
        my_array->array = (char *) (realloc(my_array->array, my_array->size * sizeof(char)));

    }
    my_array->array[++my_array->used] = element;
}

void free_array(s_array *my_array) {
    free(my_array->array);
    my_array->array = NULL;
    my_array->used = 0;
    my_array->size = 0;

}


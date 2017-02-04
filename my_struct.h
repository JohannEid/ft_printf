//
// Created by johann on 04/02/17.
//

#ifndef PRINTF_PROJECT_MY_STRUCT_H
#define PRINTF_PROJECT_MY_STRUCT_H


struct t_array;
typedef struct t_array s_array;

void init_array( s_array *, size_t initial_size);
void insert_in_array (s_array * , char );
void free_array (s_array * );



#endif //PRINTF_PROJECT_MY_STRUCT_H

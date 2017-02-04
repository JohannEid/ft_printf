//
// Created by johann on 04/02/17.
//

#include "node.h"

void add_node(s_node *head, s_array data) {
    s_node *current = head;
    if (head->data.size == 0) { head->data = data; }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (s_node *) (malloc(sizeof(struct t_node)));
    current->next->data = data;
    current->next->next = NULL;

}

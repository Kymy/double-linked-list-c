/*
 * Author: Kimberly Becerril Fuentes
 * Implementation of double linked list
 * The elements of list are of any type
 */

#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List* create_node(void* data) {
        List* new_node = (List*)malloc(sizeof(List));
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->data = data;
        return new_node;
}

bool is_empty(List* list) {
        return list == NULL;
}

bool not_null(List* list) {
        return list != NULL;
}

bool has_next(List* node) {
        return node->next != NULL;
}

List* prepend(List* list, void* data) {
        List* new_node = create_node(data);
        if (is_empty(list)) {
                return new_node;
        } else {
                new_node->next = list;
                list->prev = new_node;
        }
        return new_node;
}

List* append(List* list, void* data) {
        List* new_node = create_node(data);
        if (is_empty(list)) {
                return new_node;
        } else {
                List* temp = list;
                while (has_next(temp)) {
                        temp = temp->next;
                }
                temp->next = new_node;
                new_node->prev = temp;
        }
        return list;
}

List* get_head(List* list) {
        if (list == NULL || list->prev == NULL)
                return list;
        return get_head(list->prev);
}

List* get_tail(List* list) {
        if (is_empty(list)) {
                return NULL;
        } else {
                List* temp = list;
                while (has_next(temp)) {
                        temp = temp->next;
                }
                return temp;
        }
}

List* delete_head(List* list) {
        if (is_empty(list)) {
                return NULL;
        } else {
                list = list->next;
                free(list->prev);
        }
        return list;
}

List* delete_tail(List* list) {
        if (is_empty(list)) {
                return NULL;
        } else {
                List* temp = list;
                while (has_next(temp)) {
                        temp = temp->next;
                }
                temp->prev->next = NULL;
                free(temp->prev->next);
                return list;
        }
}

int get_list_size(List* list) {
        int size = 0;
        if (is_empty(list)) {
                return size;
        } else {
                List* temp =  list;
                while (not_null(temp)) {
                        size++;
                        temp = temp->next;
                }
        }
        return size;
}

void* get_value(List* node) {
        return node->data;
}

bool is_the_last_one(List* node, int iterator) {
        return iterator == get_list_size(node);
}

bool is_the_first(int iterator) {
        return iterator == 0;
}

List* insert_at_index(List* list, int index, void* data) {
        if (index <= get_list_size(list) && index >= 0) {
                int iterator = 0;
                List* temp = list;
                if (is_the_first(index)) {
                        return prepend(list, data);
                } else if (is_the_last_one(list, index)) {
                        return append(list, data);
                }
                while (not_null(temp)) {
                        List* new_node = create_node(data);
                        if (iterator == index) {
                                temp = temp->prev;
                                temp->next->prev = new_node;
                                new_node->next = temp->next;
                                new_node->prev = temp;
                                temp->next = new_node;
                                return list;
                        }
                        iterator++;
                        temp = temp->next;
                }
        }
        return list;
}

List* delete_at_index(List* list, int index) {
        if (index <= get_list_size(list) && index >= 0) {
                int iterator = 0;
                List* temp = list;
                if (is_the_first(index)) {
                        return delete_head(list);
                } else if(is_the_last_one(list, index)) {
                        return delete_tail(list);
                }
                while (not_null(temp)) {
                        if(iterator == index) {
                                temp->next->prev = temp->prev;
                                temp->prev->next = temp->next;
                                return list;
                        }
                        iterator++;
                        temp = temp->next;
                }
        }
        return list;
}

List* find_node_with(List* list, void* data) {
        if (is_empty(list)) {
                return NULL;
        } else {
                List* temp = list;
                while (not_null(temp)) {
                        if (temp->data == data) {
                                return temp;
                        }
                        temp = temp->next;
                }
                return NULL;
        }
}

List* find_at_index(List* list, int index) {
        if (index <= get_list_size(list) && index >= 0) {
                if (is_empty(list)) {
                        return NULL;
                } else {
                        int iterator = 0;
                        List* temp = list;
                        while (not_null(temp)) {
                                if (iterator == index) {
                                        return temp;
                                } else {
                                        iterator++;
                                        temp = temp->next;
                                }
                        }
                }
        }
        return NULL;
}

bool hasPrev(List* node) {
        return node->prev != NULL;
}

List* concatenate(List* list1, List* list2) {
        List* last_node = get_tail(list1);
        print_node(last_node);
        last_node->next = list2;
        list2->prev = last_node;
        return list1;
}

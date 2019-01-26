#pragma once

struct _List {
        void* data;
        struct _List* next;
        struct _List* prev;
};

typedef struct _List List;

List*  create_node       (void* data);
bool   is_empty          (List* list);
bool   not_null          (List* node);
bool   has_next          (List* node);
void   print_node        (List* node);
List*  prepend           (List* list,
                          void* data);
List*  append            (List* list,
                          void* data);
List*  get_head          (List* list);
List*  get_tail          (List* list);
List*  delete_head       (List* list);
List*  delete_tail       (List* list);
int    get_list_size     (List* list);
void*  get_value         (List* node);
bool   is_the_last_one   (List* node,
                          int   iterator);
bool   is_the_first      (int   iterator);
List*  insert_at_index   (List* list,
                          int   index,
                          void* data);
List*  delete_at_index   (List* list,
                          int   index);
List*  find_node_with    (List* list,
                          void* data);
List*  find_at_index     (List* list,
                          int   index);
void   print_list        (List* list);
bool   hasPrev           (List* node);
List*  concatenate       (List* list1,
                          List* list2);

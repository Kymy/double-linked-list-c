/*
 * Author: Kimberly Becerril Fuentes
 * Implementation of double linked list
 * The elements of list are char* type
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  char* data;
  struct Node* next;
  struct Node* prev;
};

struct Node* create_node(char* info) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node -> next = NULL;
  new_node -> prev = NULL;
  new_node -> data = info;
  return new_node;
}

bool is_empty(struct Node* head) {
  return head == NULL;
}

bool not_null(struct Node* node) {
  return node != NULL;
}

bool has_next(struct Node* node) {
  return node -> next != NULL;
}

void print_node(struct Node* node) {
  if (node == NULL) {
    printf("NULL\n");
  } else {
    printf("%s\n", node -> data);
  }
}

struct Node* insert_at_head(struct Node* list, char* info) {
  struct Node* new_node = create_node(info);
  if (is_empty(list)) {
    return new_node;
  } else {
    new_node -> next = list;
    list -> prev = new_node;
  }
  return new_node;
}

struct Node* insert_at_tail(struct Node* list, char* info) {
  struct Node* new_node = create_node(info);
  if (is_empty(list)) {
    return new_node;
  } else {
   struct Node* temp = list;
   while (has_next(temp)) {
    temp = temp -> next;
   }
   temp -> next = new_node;
   new_node -> prev = temp;
  }
  return list;
}

struct Node* get_head(struct Node* head) {
  return head;
}

struct Node* get_tail(struct Node* head) {
  if (is_empty(head)) {
    return NULL;
  } else {
    struct Node* temp = head;
    while (has_next(temp)) {
      temp = temp -> next;
    }
    return temp;
  }
}

struct Node* delete_head(struct Node* list) {
  if (is_empty(list)) {
    return NULL;
  } else {
    list = list -> next;
    free(list -> prev);
  }
  return list;
}

struct Node* delete_tail(struct Node* list) {
  if (is_empty(list)) {
    return NULL;
  } else {
    struct Node* temp = list;
    while (has_next(temp)) {
      temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp -> prev -> next);
    return list;
  }
}

int get_list_size(struct Node* head) {
  int size = 0;
  if (is_empty(head)) {
    return size;
  } else {
    struct Node* temp =  head;
    while (not_null(temp)) {
      size++;
      temp = temp -> next;
    }
  }
  return size;
}

char* get_value(struct Node* node) {
  return node -> data;
}

bool is_the_last_one(struct Node* node, int iterator) {
  return iterator == get_list_size(node);
}

bool is_the_first(int iterator) {
  return iterator == 0;
}

struct Node* insert_at_index(struct Node* list, int index, char* info) {
  if (index <= get_list_size(list) && index >= 0) {
    int iterator = 0;
    struct Node* temp = list;
    if (is_the_first(index)) {
      return insert_at_head(list, info);
    } else if (is_the_last_one(list, index)) {
      return insert_at_tail(list, info);
    }
    while (not_null(temp)) {
      struct Node* new_node = create_node(info);
      if (iterator == index) {
        temp = temp -> prev;
        temp -> next -> prev = new_node;
        new_node -> next = temp -> next;
        new_node -> prev = temp;
        temp -> next = new_node;
        return list;
      }
      iterator++;
      temp = temp -> next;
    }
  }
  printf("Invalid index\n");
  return list;
}

struct Node* delete_at_index(struct Node* list, int index) {
  if (index <= get_list_size(list) && index >= 0) {
    int iterator = 0;
    struct Node* temp = list;
    if (is_the_first(index)) {
      return delete_head(list);
    } else if(is_the_last_one(list, index)) {
      return delete_tail(list);
    }
    while (not_null(temp)) {
      if(iterator == index) {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        return list;
      }
      iterator ++;
      temp = temp -> next;
    }
  }
  printf("Invalid index\n");
  return list;
}

// return the first node with data equals to info
struct Node* find_node_with(struct Node* list, char * info) {
  if (is_empty(list)) {
    return NULL;
  } else {
    struct Node* temp = list;
    while (not_null(temp)) {
      if (temp -> data == info) {
        return temp;
      }
      temp = temp -> next;
    }
    return NULL;
  }
}

struct Node* find_at_index(struct Node* list, int index) {
  if (index <= get_list_size(list) && index >= 0) {
    if (is_empty(list)) {
      return NULL;
    } else {
      int iterator = 0;
      struct Node* temp = list;
      while (not_null(temp)) {
        if (iterator == index) {
          return temp;
        } else {
          iterator ++;
          temp = temp -> next;
        }
      }
    }
  }
  return NULL;
}

void print_list(struct Node* head) {
  if (is_empty(head)) {
    printf("Empty");
  }
  struct Node* temp = head;
  while (not_null(temp)) {
    print_node(temp);
    temp = temp -> next;
  }
  printf("\n");
}

bool hasPrev(struct Node* node) {
  return node -> prev != NULL;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
  struct Node* last_node = get_tail(list1);
  print_node(last_node);
  last_node -> next = list2;
  list2 -> prev = last_node;
  return list1;
}

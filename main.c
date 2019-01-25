#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "double-linked-list.c"

int main(void) {
  struct Node* list = create_node("Piche");
  list = insert_at_head(list, "Kim");
  list = insert_at_head(list, "Luis");
  list = insert_at_head(list, "Lucero");
  list = insert_at_head(list, "Susana");
  list = insert_at_tail(list, "Tabata");
  print_list(list);
  printf("Size list %d\n", get_list_size(list));
  
  printf("\nDelete head\n");
  list = delete_head(list);
  print_list(list);
  
  printf("Head %s\n", get_value(get_head(list)));
  printf("Tail %s\n", get_value(get_tail(list)));

  printf("\nDelete tail\n");
  list = delete_tail(list);
  print_list(list);

  printf("\nInsert index 3\n");
  list = insert_at_index(list, 3,"Katie");
  print_list(list);

  printf("\nInsert index 2\n");
  list = insert_at_index(list, 2,"Orlando");
  print_list(list);

  printf("\nInsert index 0\n");
  list = insert_at_index(list, 0,"José");
  print_list(list);

  printf("\nDelete index 4\n");
  list = delete_at_index(list, 4);
  print_list(list);

  printf("Searching Luis..\n");
  print_node(find_node_with(list, "Luis"));

  printf("Searching Juan..\n");
  print_node(find_node_with(list, "Juan"));

  printf("Searching index 3\n");
  print_node(find_at_index(list, 3));

  struct Node* list2 = create_node("JonSnow");
  list2 = insert_at_head(list2, "Arya");
  list2 = insert_at_head(list2, "Sansa");
  list2 = insert_at_head(list2, "Bran");
  printf("\nLista 2\n");
  print_list(list2);
  printf("Concatenate 1 and 2\n");
  list = concatenate(list, list2);
  print_list(list);
}

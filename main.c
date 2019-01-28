#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void print_node(List* node) {
        if (node == NULL) {
                printf("NULL\n");
        } else {
                printf("%s\n", (char*)node->data);
        }
}

void print_list(List* list) {
        if (is_empty(list)) {
                printf("Empty");
        }
        List* temp = list;
        while (not_null(temp)) {
                print_node(temp);
                temp = temp->next;
        }
        printf("\n");
}

int
main(int argc, char* argv[]) {
        List* list = create_node("Piche");
        list = prepend(list, "Kim");
        list = prepend(list, "Luis");
        list = prepend(list, "Lucero");
        list = prepend(list, "Susana");
        list = append(list, "Tabata");
        list = append(list, 'a');
        print_list(list);
        printf("Size list %d\n", get_list_size(list));
  
        printf("\nDelete head\n");
        list = delete_head(list);
        print_list(list);
  
        printf("Head %s\n", (char*)get_head(list)->data);
        printf("Tail %s\n", (char*)get_tail(list)->data);

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

        List* list2 = create_node("JonSnow");
        list2 = prepend(list2, "Arya");
        list2 = prepend(list2, "Sansa");
        list2 = prepend(list2, "Bran");
        printf("\nLista 2\n");
        print_list(list2);
        printf("Concatenate 1 and 2\n");
        list = concatenate(list, list2);
        print_list(list);

        return 0;
}

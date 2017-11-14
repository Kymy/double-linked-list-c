/*
 * Author: Kimberly Becerril Fuentes
 * Implementation of double linked list
 * The elememnts of the list are char type
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  char* data;
  struct Node* next;
  struct Node* prev;
};

//Create a new node
struct Node* createNode(char* info){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->data = info;
  return newNode;
}

bool isEmpty(struct Node* head){
  return head == NULL;
}

bool notNull(struct Node* node){
  return node != NULL;
}

bool hasNext(struct Node* node){
  return node->next != NULL;
}

void printNode(struct Node* node){
  if(node == NULL) {
    printf("NULL\n");
  } else{
    printf("%s\n", node->data);    
  }
}

struct Node* insertAtHead(struct Node* list, char* info){
  struct Node* newNode = createNode(info);
  if(isEmpty(list)){
    return newNode;
  }else{
    newNode->next = list;
    list->prev = newNode;
  }
  return newNode;
}

struct Node* insertAtTail(struct Node* list, char* info){
  struct Node* newNode = createNode(info);
  if(isEmpty(list)){
    return newNode;
  }else{
   struct Node* temp = list;
   while(hasNext(temp)){
    temp = temp->next;
   }
   temp->next = newNode;
   newNode->prev = temp;
  }
  return list;
}

struct Node* getHead(struct Node* head){
  return head;
}

struct Node* getTail(struct Node* head) {
  if(isEmpty(head)){
    return NULL;
  }else{
    struct Node* temp = head;
    while(hasNext(temp)){
      temp = temp -> next;
    }
    return temp;
  }
}

struct Node* deleteHead(struct Node* list){
  if(isEmpty(list)){
    return NULL;
  }else{
    list = list->next;
    free(list->prev);
  }
  return list;
}

struct Node* deleteTail(struct Node* list){
  if(isEmpty(list)){
    return NULL;
  }else{
    struct Node* temp = list;
    while(hasNext(temp)){
      temp = temp -> next;
    }
    temp->prev->next = NULL;
    free(temp->prev->next);
    return list;
  }
}

int getListSize(struct Node* head){
  int size = 0;
  if(isEmpty(head)){
    return size;
  }else{
    struct Node* temp =  head;
    while(notNull(temp)){
      size++;
      temp = temp->next;
    }
  }
  return size;
}

char* getValue(struct Node* node){
  return node->data;
}

bool isTheLastOne(struct Node* node, int iterator){
  return iterator == getListSize(node);
}

bool isTheFirst(int iterator){
  return iterator == 0;
}

struct Node* insertAtIndex(struct Node* list, int index, char* info){
  if(index <= getListSize(list) && index>=0){
    int iterator = 0;
    struct Node* temp =  list;
    if(isTheFirst(index)){
      return insertAtHead(list, info);
    }else if(isTheLastOne(list, index)){
      return insertAtTail(list, info);
    }
    while(notNull(temp)){
      struct Node* newNode = createNode(info);
      if(iterator == index){
        temp = temp->prev;
        temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        return list;
      }
      iterator++;
      temp = temp->next;
    }
  }else{
    printf("Invalid index\n");
    return list;
  }
}

struct Node* deleteAtIndex(struct Node* list, int index){
  if(index <= getListSize(list) && index>=0){
    int iterator = 0;
    struct Node* temp =  list;
    if(isTheFirst(index)){
      return deleteHead(list);
    }else if(isTheLastOne(list, index)){
      return deleteTail(list);
    }
    while(notNull(temp)){
      if(iterator == index){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        return list;
      }
      iterator++;
      temp = temp->next;
    }
  }else{
    printf("Invalid index\n");
    return list;
  }
}

//return the first node with data equals to info
struct Node* findNodeWith(struct Node* list, char * info){
  if(isEmpty(list)){
    return NULL;
  }else{
    struct Node* temp = list;
    while(notNull(temp)){
      if(temp->data == info){
        return temp;
      }
      temp = temp -> next;
    }
    return NULL;
  }
}

struct Node* findAtIndex(struct Node* list, int index) {
  if(index <= getListSize(list) && index>=0){
    if(isEmpty(list)){
      return NULL;
    }else{
      int iterator = 0;
      struct Node* temp = list;
      while(notNull(temp)) {
        if (iterator == index) {
          return temp;
        }else{
          iterator++;
          temp = temp -> next;
        }
      }
    }
  }
  return NULL;
}

void printList(struct Node* head){
  if(isEmpty(head)){
    printf("Empty");
  }
  struct Node* temp = head;
  while(notNull(temp)){
    printNode(temp);
    temp = temp->next;
  }
  printf("\n");
}

int main(void){
  struct Node* list = createNode("Piche");
  list = insertAtHead(list, "Kim");
  list = insertAtHead(list, "Luis");
  list = insertAtHead(list, "Lucero");
  list = insertAtHead(list, "Susana");
  list = insertAtTail(list, "Tabata");
  printList(list);
  printf("Size list %d\n", getListSize(list));
  
  printf("\nDelete head\n");
  list = deleteHead(list);
  printList(list);
  
  printf("Head %s\n", getValue(getHead(list)));
  printf("Tail %s\n", getValue(getTail(list)));

  printf("\nDelete tail\n");
  list = deleteTail(list);
  printList(list);

  printf("\nInsert index 3\n");
  list = insertAtIndex(list, 3,"Katie");
  printList(list);

  printf("\nInsert index 2\n");
  list = insertAtIndex(list, 2,"Orlando");
  printList(list);

  printf("\nInsert index 0\n");
  list = insertAtIndex(list, 0,"José");
  printList(list);

  printf("\nDelete index 4\n");
  list = deleteAtIndex(list, 4);
  printList(list);

  printf("Buscando Luis..\n");
  printNode(findNodeWith(list, "Luis"));

  printf("Buscando Juan..\n");
  printNode(findNodeWith(list, "Juan"));

  printf("Buscando index 3\n");
  printNode(findAtIndex(list, 3));


}
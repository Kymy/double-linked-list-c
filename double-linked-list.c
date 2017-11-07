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

struct Node* head;

//Create a new node
struct Node* createNode(char* info){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->data = info;
  return newNode;
}

bool isEmpty(){
  return head == NULL;
}

void initializeList(){
  head = NULL;
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

void insertAtHead(char* info){
  struct Node* newNode = createNode(info);
  if(isEmpty()){
    head = newNode;
    return;
  }else{
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void insertAtTail(char* info){
  struct Node* newNode = createNode(info);
  if(isEmpty()){
    head = newNode;
    return;
  }else{
   struct Node* temp = head;
   while(hasNext(temp)){
    temp = temp->next;
   }
   temp->next = newNode;
   newNode->prev = temp;
  }
}

struct Node* getHead(){
  return head;
}

struct Node* getTail() {
  if(isEmpty()){
    return NULL;
  }else{
    struct Node* temp = head;
    while(hasNext(temp)){
      temp = temp -> next;
    }
    return temp;
  }
}

void deleteHead(){
  if(isEmpty()){
    return;
  }else{
    head = head->next;
    free(head->prev);
  }
}

void deleteTail(){
  if(isEmpty()){
    return;
  }else{
    struct Node* temp = head;
    while(hasNext(temp)){
      temp = temp -> next;
    }
    temp->prev->next = NULL;
  }
}

int getListSize(){
  int size = 0;
  if(isEmpty()){
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

bool isTheLastOne(iterator){
  return iterator == getListSize();
}

bool isTheFirst(iterator){
  return iterator == 0;
}

void insertAtIndex(int index, char* info){
  if(index <= getListSize() && index>=0){
    int iterator = 0;
    struct Node* temp =  head;
    if(isTheFirst(index)){
      insertAtHead(info);
      return;
    }else if(isTheLastOne(index)){
      insertAtTail(info);
      return;
    }
    while(notNull(temp)){
      struct Node* newNode = createNode(info);
      if(iterator == index){
        temp = temp->prev;
        temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        return;
      }
      iterator++;
      temp = temp->next;
    }
  }else{
    printf("Invalid index\n");
  }
}

void deleteAtIndex(int index){
  if(index <= getListSize() && index>=0){
    int iterator = 0;
    struct Node* temp =  head;
    if(isTheFirst(index)){
      deleteHead();
      return;
    }else if(isTheLastOne(index)){
      deleteTail();
      return;
    }
    while(notNull(temp)){
      if(iterator == index){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        return;
      }
      iterator++;
      temp = temp->next;
    }
  }else{
    printf("Invalid index\n");
  }
}


//return the first node with data equals to info
struct Node* findNodeWith(char * info){
  if(isEmpty()){
    return NULL;
  }else{
    struct Node* temp = head;
    while(notNull(temp)){
      if(temp->data == info){
        return temp;
      }
      temp = temp -> next;
    }
    return NULL;
  }
}

struct Node* findAtIndex(int index) {
  if(index <= getListSize() && index>=0){
    if(isEmpty()){
      return NULL;
    }else{
      int iterator = 0;
      struct Node* temp = head;
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

void printList(){
  if(isEmpty()){
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
  printList();
  initializeList();
  insertAtHead("Kim");
  insertAtHead("Luis");
  insertAtHead("Lucero");
  insertAtTail("Tabata");
  insertAtHead("Susana");
  
  printList();
  printf("Size list %d\n", getListSize());
  
  printf("\nDelete head\n");
  deleteHead();
  printList();
  
  printf("Head %s\n", getValue(getHead()));
  printf("Tail %s\n", getValue(getTail()));

  printf("\nDelete tail\n");
  deleteTail();
  printList();

  printf("\nInsert index 3\n");
  insertAtIndex(3,"Katie");
  printList();

  printf("\nInsert index 2\n");
  insertAtIndex(2,"Orlando");
  printList();

  printf("\nInsert index 0\n");
  insertAtIndex(0,"José");
  printList();

  printf("\nDelete index 4\n");
  deleteAtIndex(4);
  printList();

  printf("Buscando Luis..\n");
  printNode(findNodeWith("Luis"));

  printf("Buscando Juan..\n");
  printNode(findNodeWith("Juan"));

  printf("Buscando index 3\n");
  printNode(findAtIndex(3));


}
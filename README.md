# Double linked list

A linked list is a linear data structure.
This implementation is written in C and the elements in list are of type _void *_.

## 

Elements are represented with node structures. Each node holds three properties:

```c
struct _List {
        void* data; // stores the data value 
        struct Node* next; // pointer to the next node
        struct Node* prev; // pointer to the previous node
};
```
##

To compile:

`gcc list.c main.c -o main`

To execute:

`.\main`




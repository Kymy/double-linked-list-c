# Double linked list

A linked list is a linear data structure.
This implementation is written in C and the elements in list are of type char *.

## 

Elements are represented with node structures. Each node holds three properties:

```c
struct Node {
  char* data; // stores the data value 
  struct Node* next; // pointer to the next node
  struct Node* prev; // pointer tho the previous node
};
```


#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct Node Node; 
struct Node {
    void* data;

    Node* next;
    Node* prev;
};

typedef struct List List;
struct List {
    Node* head;
    Node* tail;
};

List* init_list ();
void free_list (List* list);

void traverse_list (List* list, void (*callback)(void*));

void insert_front (List* list, void* data);
void insert_back (List* list, void* data);
void insert_after (List* list, Node* node, void* data);
void insert_before (List* list, Node* node, void* data);

void delete_from (List* list, Node* node);

#endif /* __LIST_H__ */

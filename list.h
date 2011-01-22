#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

struct Node {
    void* data;

    struct Node* next;
    struct Node* prev;
};

struct List {
    struct Node* head;
    struct Node* tail;
};

struct List* init_list ();
void free_list (struct List* list);

void traverse_list (struct List* list, void (*callback)(void*));

void insert_front (struct List* list, void* data);
void insert_back (struct List* list, void* data);
void insert_after (struct List* list, struct Node* node, void* data);
void insert_before (struct List* list, struct Node* node, void* data);

void delete_from (struct List* list, struct Node* node);

#endif /* __LIST_H__ */

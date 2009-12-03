#ifndef __LIST_H__
#define __LIST_H__

typedef struct Node Node; 
struct Node {
    char* name;

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

void traverse_list (List* list, void (*callback)(char* name));

void insert_front (List* list, char* data);
void insert_back (List* list, char* data);
void insert_after (List* list, Node* node, char* data);
void insert_before (List* list, Node* node, char* data);

void delete_from (List* list, Node* node);

#endif /* __LIST_H__ */

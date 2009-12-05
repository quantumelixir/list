#include <string.h>
#include <malloc.h>

#include "list.h"

/* Simple and clean doubly linked list to store strings
 *
 * what is supported:
 * -> Create a new list
 * -> Delete list
 * -> Traverse list
 * -> Add node
 * -> Delete node
 */

List*
init_list () {
    List* list = (List *) malloc (sizeof (List));
    list->head = list->tail = NULL;
    return list;
}

void
free_list (List* list) {
    Node* current = list->head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        free (current);
        current = next;
    }
    free (list);
}

void
traverse_list (List* list, void (*callback)(char* name)) {
    Node* current = list->head;
    while (current) {
        callback (current->name);
        current = current->next;
    }
}

/* 
 * When prev is NULL it inserts before the head
 */
void
insert_after (List* list, Node* prev, char* data) {
    Node* next = prev ? prev->next : list->head;

    Node* newnode = (Node *) malloc (sizeof (Node));
    newnode->name = data;

    newnode->prev = prev;
    newnode->next = next;

    prev ? prev->next = newnode : 0 ;
    next ? next->prev = newnode : 0 ;

    list->head == NULL ? list->head = list->tail = newnode :
        prev == NULL ? list->head = newnode : 0 ;
}

/* 
 * When next is NULL it inserts after the tail
 */
void
insert_before (List* list, Node* next, char* data) {
    Node* prev = next ? next->prev : list->tail;

    Node* newnode = (Node *) malloc (sizeof (Node));
    newnode->name = data;

    newnode->prev = prev;
    newnode->next = next;

    next ? next->prev = newnode : 0 ;
    prev ? prev->next = newnode : 0 ;

    list->tail == NULL ? list->head = list->tail = newnode :
        next == NULL ? list->tail = newnode : 0 ;
}

void
insert_front (List* list, char* data) {
    insert_after (list, NULL, data);
}

void
insert_back (List* list, char* data) {
    insert_before (list, NULL, data);
}

void
delete_from (List* list, Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;

    prev ? prev->next = next : 0 ;
    next ? next->prev = prev : 0 ;

    node == list->head ? list->head = next : 0 ;
    node == list->tail ? list->tail = prev : 0 ;

    free (node->name);
    free (node);
}

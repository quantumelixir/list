#include <stdio.h>
#include <ncurses.h>

#include "list.h"

void
print_string (char* s) {
    printf ("%s\n", s);
}

int
main (int argc, char **argv) {

    /* ncurses interface
     * a: insert_after
     * b: insert_before
     * d: delete_node
     */

    List* list = init_list ();
    insert_front (list, "asdf");
    insert_front (list, "jkl;");
    insert_back (list, "joe");
    insert_front (list, "molly");
    insert_back (list, "bob");
    insert_back (list, "SDFSDF!!@@@");
    delete_from (list, list->head->next);
    delete_from (list, list->tail);
    insert_before (list, list->head->next, "boom!");
    traverse_list (list, print_string);
    free_list (list);

    return 0;
}

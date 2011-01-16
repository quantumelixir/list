package golist

/*
#include <stdio.h>
#include "../list.h"
*/
import "C"

import "fmt"

func Demo() {
    list := C.init_list()
    C.insert_front (list, C.CString("asdf"));
    C.insert_front (list, C.CString("jkl;"));
    C.insert_back (list, C.CString("joe"));
    C.insert_front (list, C.CString("molly"));
    C.insert_back (list, C.CString("bob"));
    C.insert_back (list, C.CString("SDFSDF!!@@@"));
    C.delete_from (list, (*((*list).head)).next);
    C.delete_from (list, (*list).tail);
    C.insert_before (list, (*((*list).head)).next, C.CString("boom!"));

    for p := (*list).head; p != nil; p = (*p).next {
        fmt.Println(p)
    }

    C.free_list(list)
}

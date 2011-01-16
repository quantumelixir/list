include $(GOROOT)/src/Make.inc

TARG=golist
CGOFILES=golist.go
CGO_LDFLAGS=-L../build/ -llist

include $(GOROOT)/src/Make.pkg

CLEANFILES+=main

main: install main.go
	$(GC) main.go
	$(LD) -o $@ main.$O

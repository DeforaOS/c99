TARGETS	= graph hello struct union
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= ../src/c99
CPPFLAGSF?=
CPPFLAGS?=
CFLAGSF	= -W
CFLAGS	=
RM	?= rm -f
LN	?= ln -f
MKDIR	?= mkdir -p
INSTALL	?= install


all: $(TARGETS)

graph_OBJS = graph
graph_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS) -M graph

hello_OBJS = hello
hello_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

struct_OBJS = struct
struct_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

union_OBJS = union
union_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

graph: graph.c
	$(CC) $(graph_CFLAGS) -c graph.c

hello: hello.c
	$(CC) $(hello_CFLAGS) -c hello.c

struct: struct.c
	$(CC) $(struct_CFLAGS) -c struct.c

union: union.c
	$(CC) $(union_CFLAGS) -c union.c

clean:
	$(RM) -- $(graph_OBJS) $(hello_OBJS) $(struct_OBJS) $(union_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)

uninstall:

.PHONY: all clean distclean install uninstall

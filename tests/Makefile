TARGETS	= graph.o hello.o struct.o union.o
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= ../src/c99
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W
CFLAGS	=
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

graph.o_OBJS = graph.o
graph.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS) -M graph

hello.o_OBJS = hello.o
hello.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

struct.o_OBJS = struct.o
struct.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

union.o_OBJS = union.o
union.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

graph.o: graph.c
	$(CC) $(graph.o_CFLAGS) -c graph.c

hello.o: hello.c
	$(CC) $(hello.o_CFLAGS) -c hello.c

struct.o: struct.c
	$(CC) $(struct.o_CFLAGS) -c struct.c

union.o: union.c
	$(CC) $(union.o_CFLAGS) -c union.c

clean:
	$(RM) -- $(graph.o_OBJS) $(hello.o_OBJS) $(struct.o_OBJS) $(union.o_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)

uninstall:

.PHONY: all clean distclean install uninstall

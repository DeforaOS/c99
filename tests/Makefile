TARGETS	= $(OBJDIR)graph.o $(OBJDIR)hello.o $(OBJDIR)struct.o $(OBJDIR)union.o
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= ./c99.sh
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W
CFLAGS	=
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

graph.o_OBJS = $(OBJDIR)graph.o
graph.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS) -M graph

hello.o_OBJS = $(OBJDIR)hello.o
hello.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

struct.o_OBJS = $(OBJDIR)struct.o
struct.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

union.o_OBJS = $(OBJDIR)union.o
union.o_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)

$(OBJDIR)graph.o: graph.c
	$(CC) $(graph.o_CFLAGS) -o $(OBJDIR)graph.o -c graph.c

$(OBJDIR)hello.o: hello.c
	$(CC) $(hello.o_CFLAGS) -o $(OBJDIR)hello.o -c hello.c

$(OBJDIR)struct.o: struct.c
	$(CC) $(struct.o_CFLAGS) -o $(OBJDIR)struct.o -c struct.c

$(OBJDIR)union.o: union.c
	$(CC) $(union.o_CFLAGS) -o $(OBJDIR)union.o -c union.c

clean:
	$(RM) -- $(graph.o_OBJS) $(hello.o_OBJS) $(struct.o_OBJS) $(union.o_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)

uninstall:

.PHONY: all clean distclean install uninstall

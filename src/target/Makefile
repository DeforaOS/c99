TARGETS	= $(OBJDIR)asm.so $(OBJDIR)graph.so $(OBJDIR)indent.so
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
LIBDIR	= $(PREFIX)/lib
CC	= cc
CPPFLAGSF= -I ../../include
CPPFLAGS=
CFLAGSF	= `pkg-config --cflags cpp` -fPIC
CFLAGS	= -W -Wall -g -O2 -pedantic -D_FORTIFY_SOURCE=2 -fstack-protector-all
LDFLAGSF= `pkg-config --libs cpp`
LDFLAGS	= -Wl,-z,relro -Wl,-z,now
AR	= ar
RANLIB	= ranlib
CCSHARED= $(CC) -shared
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

asm_OBJS = $(OBJDIR)asm.o
asm_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS) `pkg-config --cflags Asm`
asm_LDFLAGS = $(LDFLAGSF) $(LDFLAGS) `pkg-config --libs Asm`

$(OBJDIR)asm.so: $(asm_OBJS)
	$(CCSHARED) -o $(OBJDIR)asm.so $(asm_OBJS) $(asm_LDFLAGS)

graph_OBJS = $(OBJDIR)graph.o
graph_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
graph_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)graph.so: $(graph_OBJS)
	$(CCSHARED) -o $(OBJDIR)graph.so $(graph_OBJS) $(graph_LDFLAGS)

indent_OBJS = $(OBJDIR)indent.o
indent_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
indent_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)indent.so: $(indent_OBJS)
	$(CCSHARED) -o $(OBJDIR)indent.so $(indent_OBJS) $(indent_LDFLAGS)

$(OBJDIR)asm.o: asm.c ../../include/C99/target.h asm/amd64.c asm/i386.c asm/i486.c asm/i586.c asm/i686.c ../../config.h
	$(CC) $(asm_CFLAGS) -o $(OBJDIR)asm.o -c asm.c

$(OBJDIR)graph.o: graph.c ../../include/C99/target.h
	$(CC) $(graph_CFLAGS) -o $(OBJDIR)graph.o -c graph.c

$(OBJDIR)indent.o: indent.c ../../include/C99/target.h
	$(CC) $(indent_CFLAGS) -o $(OBJDIR)indent.o -c indent.c

clean:
	$(RM) -- $(asm_OBJS) $(graph_OBJS) $(indent_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	$(MKDIR) $(DESTDIR)$(LIBDIR)/C99/target
	$(INSTALL) -m 0755 $(OBJDIR)asm.so $(DESTDIR)$(LIBDIR)/C99/target/asm.so
	$(MKDIR) $(DESTDIR)$(LIBDIR)/C99/target
	$(INSTALL) -m 0755 $(OBJDIR)graph.so $(DESTDIR)$(LIBDIR)/C99/target/graph.so
	$(MKDIR) $(DESTDIR)$(LIBDIR)/C99/target
	$(INSTALL) -m 0755 $(OBJDIR)indent.so $(DESTDIR)$(LIBDIR)/C99/target/indent.so

uninstall:
	$(RM) -- $(DESTDIR)$(LIBDIR)/C99/target/asm.so
	$(RM) -- $(DESTDIR)$(LIBDIR)/C99/target/graph.so
	$(RM) -- $(DESTDIR)$(LIBDIR)/C99/target/indent.so

.PHONY: all clean distclean install uninstall

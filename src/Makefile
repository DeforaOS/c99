SUBDIRS	= sets target
TARGETS	= $(OBJDIR)c99
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= cc
CPPFLAGSF=
CPPFLAGS=
CFLAGSF	= -W `pkg-config --cflags cpp`
CFLAGS	= -Wall -g -O2 -pedantic
LDFLAGSF= `pkg-config --libs cpp`
LDFLAGS	= -L$(PREFIX)/lib -Wl,-rpath,$(PREFIX)/lib
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: subdirs $(TARGETS)

subdirs:
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		([ -d "$(OBJDIR)$$i" ] || $(MKDIR) -- "$(OBJDIR)$$i") && \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/"; \
		else $(MAKE); fi) || exit; done

c99_OBJS = $(OBJDIR)c99.o $(OBJDIR)code.o $(OBJDIR)main.o $(OBJDIR)parser.o $(OBJDIR)scanner.o $(OBJDIR)tokenset.o
c99_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
c99_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)c99: $(c99_OBJS)
	$(CC) -o $(OBJDIR)c99 $(c99_OBJS) $(c99_LDFLAGS)

$(OBJDIR)c99.o: c99.c common.h code.h parser.h ../include/C99.h
	$(CC) $(c99_CFLAGS) -o $(OBJDIR)c99.o -c c99.c

$(OBJDIR)code.o: code.c ../include/C99/target.h code.h ../config.h
	$(CC) -D PREFIX=\"$(PREFIX)\" $(c99_CFLAGS) -o $(OBJDIR)code.o -c code.c

$(OBJDIR)main.o: main.c ../include/C99.h ../config.h
	$(CC) $(c99_CFLAGS) -o $(OBJDIR)main.o -c main.c

$(OBJDIR)parser.o: parser.c common.h code.h tokenset.h scanner.h ../include/C99.h ../config.h
	$(CC) $(c99_CFLAGS) -o $(OBJDIR)parser.o -c parser.c

$(OBJDIR)scanner.o: scanner.c ../include/C99.h ../config.h
	$(CC) $(c99_CFLAGS) -o $(OBJDIR)scanner.o -c scanner.c

$(OBJDIR)tokenset.o: tokenset.c common.h code.h tokenset.h
	$(CC) $(c99_CFLAGS) -o $(OBJDIR)tokenset.o -c tokenset.c

clean:
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/" clean; \
		else $(MAKE) clean; fi) || exit; done
	$(RM) -- $(c99_OBJS)

distclean:
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/" distclean; \
		else $(MAKE) distclean; fi) || exit; done
	$(RM) -- $(c99_OBJS)
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/" install; \
		else $(MAKE) install; fi) || exit; done
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 0755 $(OBJDIR)c99 $(DESTDIR)$(BINDIR)/c99

uninstall:
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/" uninstall; \
		else $(MAKE) uninstall; fi) || exit; done
	$(RM) -- $(DESTDIR)$(BINDIR)/c99

.PHONY: all subdirs clean distclean install uninstall

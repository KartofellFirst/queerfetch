SRC = src/fetch.c
CC ?= cc
CFLAGS = -O2 -std=c99 -Wall -Wextra
LDFLAGS = -lpthread
PREFIX ?= /usr/local

all: queerfetch

queerfetch: 
	${CC} ${CFLAGS} ${SRC} ${LDFLAGS} -o queerfetch

clean:
	rm -rf queerfetch queerfetch.dSYM queerfetch-debug queerfetch-debug.dSYM

install: queerfetch
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp queerfetch ${DESTDIR}${PREFIX}/bin
	chmod 711 ${DESTDIR}${PREFIX}/bin/queerfetch

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/queerfetch

.PHONY: all clean debug install uninstall

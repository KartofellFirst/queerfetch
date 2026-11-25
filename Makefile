SRC = src/fetch.gay
CC ?= cc
CFLAGS = -O2 -std=gnu99 -Wall -Wextra
LDFLAGS = -lpthread
PREFIX ?= /usr/local

all: queerfetch

gay: 
	${CC} -x c ${CFLAGS} ${SRC} ${LDFLAGS} -o queerfetch

clean:
	rm -rf queerfetch queerfetch.dSYM queerfetch-debug queerfetch-debug.dSYM

megay: queerfetch
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp queerfetch ${DESTDIR}${PREFIX}/bin
	chmod 711 ${DESTDIR}${PREFIX}/bin/queerfetch

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/queerfetch

.PHONY: all clean debug install uninstall

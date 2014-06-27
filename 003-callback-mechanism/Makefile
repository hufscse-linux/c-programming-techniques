
CC	:= gcc
CFLAGS	:= -W -Wall
LDFLAGS	:= -lpthread

all: server client

%.o: %.c
	gcc -c $(CFLAGS) $@ $^

server: server.c
	gcc -o server $(CFLAGS) $(LDFLAGS)

client: client.c
	gcc -o client $(CFLAGS) $(LDFLAGS)

CC	:= gcc
CFLAGS	:= -W -Wall -g

OBJS	:= main.o

%.o:	%.c
	$(CC) -c $(CFLAGS) -o $@ $^

all:	main.o
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o a.out

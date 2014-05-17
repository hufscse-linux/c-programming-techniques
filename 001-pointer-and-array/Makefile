CC	:= gcc
CFLAGS	:= -W -Wall -g

%.o:	%.c
	$(CC) -c $(CFLAGS) -o $@ $^

all: case1 case2

case1:	case1.o
	$(CC) $(CFLAGS) -o $@ $^

case2:	case2.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o case*

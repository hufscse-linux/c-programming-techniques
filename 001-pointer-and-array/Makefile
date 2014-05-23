CC	:= gcc
CFLAGS	:= -W -Wall -g
BINS	:= case1 case2

%.o:	%.c
	$(CC) -c $(CFLAGS) -o $@ $^

all: $(BINS)

case1:	case1.o
	$(CC) $(CFLAGS) -o $@ $^

case2:	case2.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o $(BINS)

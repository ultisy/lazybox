CC = aarch64-linux-gcc
CFLAGS = -Wall -Wextra -std=c99

all: busybox

ls.o: ls.c
	$(CC) $(CFLAGS) -c ls.c

cp.o: cp.c
	$(CC) $(CFLAGS) -c cp.c

mv.o: mv.c
	$(CC) $(CFLAGS) -c mv.c

rm.o: rm.c
	$(CC) $(CFLAGS) -c rm.c

cat.o: cat.c
	$(CC) $(CFLAGS) -c cat.c

grep.o: grep.c
	$(CC) $(CFLAGS) -c grep.c

busybox: main.c ls.o cp.o mv.o rm.o cat.o grep.o
	$(CC) $(CFLAGS) -o busybox main.c ls.o cp.o mv.o rm.o cat.o grep.o

clean:
	rm -f *.o busybox

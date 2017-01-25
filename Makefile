CC=c++
CFLAGS=-std=gnu++14 -Wall -Wextra

debug:clean
	$(CC) $(CFLAGS) -g -o valuePacking main.cpp
stable:clean
	$(CC) $(CFLAGS) -O2 -o valuePacking main.cpp
clean:
	rm -vfr *~ valuePacking

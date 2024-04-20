CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: 111

111: main-vektoriai.cpp vektoriai.cpp failu-generavimas.cpp
	$(CC) $(CFLAGS) -O2 $^ -o $@

clean:
	rm -f 111

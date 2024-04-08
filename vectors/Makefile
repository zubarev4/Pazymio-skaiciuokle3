CC = g++
CFLAGS = -Wall -std=c++17

.PHONY: all clean

all: vektoriai_O1 vektoriai_O2 vektoriai_O3

vektoriai_O1: main-vektoriai.cpp vektoriai.cpp failu-generavimas.cpp
	$(CC) $(CFLAGS) -O1 $^ -o $@

vektoriai_O2: main-vektoriai.cpp vektoriai.cpp failu-generavimas.cpp
	$(CC) $(CFLAGS) -O2 $^ -o $@

vektoriai_O3: main-vektoriai.cpp vektoriai.cpp failu-generavimas.cpp
	$(CC) $(CFLAGS) -O3 $^ -o $@

clean:
	rm -f vektoriai_O1 vektoriai_O2 vektoriai_O3


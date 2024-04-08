CC = g++
CFLAGS = -O3 -Wall -std=c++17

all: main-vektoriai.o vektoriai.o failu-generavimas.o
	$(CC) $(CFLAGS) main-vektoriai.o vektoriai.o failu-generavimas.o -o run

main-vektoriai.o: main-vektoriai.cpp
	$(CC) $(CFLAGS) -c main-vektoriai.cpp
    
vektoriai.o: vektoriai.cpp vektoriai.h
	$(CC) $(CFLAGS) -c vektoriai.cpp

failu-generavimas.o: failu-generavimas.cpp failu-generavimas.h
	$(CC) $(CFLAGS) -c failu-generavimas.cpp

clean:
	rm -f *.o run.exe

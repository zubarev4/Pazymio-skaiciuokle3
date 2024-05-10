CC = g++
CFLAGS = -Wall -std=c++17
TEST_CPPFLAGS = -std=c++14

.PHONY: all clean test

all: 111 test

111: main-vektoriai.cpp vektoriai.cpp failu-generavimas.cpp
	$(CC) $(CFLAGS) -O2 $^ -o $@

test: student.h testing-main.cpp catch_amalgamated.cpp
	$(CC) $(CFLAGS) $(TEST_CPPFLAGS) -o test-run testing-main.cpp catch_amalgamated.cpp
	./test-run

clean:
	rm -f 111 test-run


CC = g++
CFLAGS = -g

all: main


main: main.o ItemType.o SortedLinkedList.o
	$(CC) $(CFLAGS) main.cpp ItemType.cpp SortedLinkedList.cpp -o main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f sfind

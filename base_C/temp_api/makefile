CC = gcc
CFLAGS = -c  -std=c99 -Wall
OBJECTS = main.o temp_api.o
MYLIB = temp_api.h
EXEC = report

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS)

main.o: main.c $(MYLIB)
	$(CC)  $(CFLAGS) -o main.o main.c 

clean:
	rm -rf $(OBJECTS) $(EXEC)
 
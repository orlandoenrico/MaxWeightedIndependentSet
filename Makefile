exato_TARGET = ./exato
heuristica_TARGET = ./heuristica
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -O2 -g

CLEAN = rm *.o
 
.PHONY: default all clean
 
default: $(exato_TARGET) $(heuristica_TARGET)
all: default
 
exato_OBJECTS = $(patsubst %.c, %.o, exato.c mainE.c)
exato_HEADERS = $(T.h exato.h)
 
heuristica_OBJECTS = $(patsubst %.c, %.o, heuristica.c mainH.c)
heuristica_HEADERS = $(T.h heuristica.h)
 
%.o: %.c $(exato_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
   
%.o: %.c $(heuristica_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
     
.PRECIOUS: $(exato_TARGET) $(exato_OBJECTS) $(heuristica_TARGET) $(heuristica_OBJECTS)
 
$(exato_TARGET): $(exato_OBJECTS)
	$(CC) $(exato_OBJECTS) -o $@
     
$(heuristica_TARGET): $(heuristica_OBJECTS)
	$(CC) $(heuristica_OBJECTS) -o $@
     
clean:
	$(CLEAN)

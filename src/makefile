CC=g++
CFLAGS=-Wall -g -g -O2 -c
LFLAGS=-Wall -g -g -O2
LIBS=-L/usr/lib -lSDL -lSDLmain
INCLUDES=-I. -I/usr/include -I/usr/include/SDL
BINFILE=multris

CCMD=$(CC) $(INCLUDES) $(CFLAGS)
LCMD=$(CC) $(LFLAGS) $(LIBS)

all: main

clean:
	rm *.o $(BINFILE)

main: main.o Game.o Renderer.o Engine.o
	$(LCMD)	-o $(BINFILE) \
	Board.o main.o Game.o Renderer.o Engine.o

main.o: main.cpp
	$(CCMD) main.cpp

renderer: Renderer.o

Game.o: Board.o
	$(CCMD) Game.cpp

Renderer.o:
	$(CCMD) Renderer.cpp

Board.o: 
	$(CCMD) Board.cpp

Engine.o: 
	$(CCMD) Engine.cpp


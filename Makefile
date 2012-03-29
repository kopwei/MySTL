#i am a comment
CC=g++
#Hey! i am comment

CFLAGS = -c -Wall

all: MySTL

MySTL: Main.o mystring.o
	$(CC) Main.o mystring.o -o MySTL

Main.o: src/Main.cpp
	$(CC) $(CFLAGS) src/Main.cpp

mystring.o: src/mystring.cpp
	$(CC) $(CFLAGS) src/mystring.cpp

clean:
	rm -rf *o MySTL

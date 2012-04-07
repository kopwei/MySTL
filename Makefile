#i am a comment
CC=g++
#Hey! i am comment

CFLAGS = -g -c -Wall

OBJECTS = out/Main.o out/mystring.o

all: bin/MySTL

bin/MySTL: $(OBJECTS) | bin
	$(CC) $(OBJECTS) -o bin/MySTL

out/Main.o: src/Main.cpp | out
	$(CC) $(CFLAGS) src/Main.cpp -o out/Main.o

out/mystring.o: src/mystring.cpp | out
	
	$(CC) $(CFLAGS) src/mystring.cpp -o out/mystring.o

out:
	mkdir -p out

bin:
	mkdir -p bin

.PHONY: clean
clean:
	rm -rf bin
	rm -rf out

CC = gcc
CFLAGS = -lm -lGL -lSDL2 -lSDL2_ttf
DEPS = *.h

makemain: main.c
	$(CC) -g -o main *.c $(CFLAGS)

sdl: main.c
	$(CC) *.c -o main -lGL -lSDL2 -lSDL2_ttf

clean:
	rm main

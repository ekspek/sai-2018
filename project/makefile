CC = gcc
CFLAGS = -lm -lGL -lSDL2
DEPS = *.h

makemain: main.c
	$(CC) -g -o main *.c $(CFLAGS)

sdl: main.c
	$(CC) *.c -o main -lGL -lSDL2

comms: comms.c
	$(CC) comms.c -o comms -lpthread -lm

clean:
	rm main

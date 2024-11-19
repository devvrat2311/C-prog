executable: objex
	cc main.o gorilla.o -o spacez

objex:
	cc -c src/gorilla.c main.c

clean:
	rm main.o gorilla.o spacez

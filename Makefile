jeux: jeux.o
	gcc  jeux.o -lSDL -lSDL_image -lSDL_mixer -o jeux
main.o:jeux.c
	gcc -c jeux.c

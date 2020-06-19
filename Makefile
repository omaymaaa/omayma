prog:main.o rotozoom.o
	gcc   main.o rotozoom.o -o prog -lSDL -lSDL_image -lm -lSDL_gfx
main.o:main.c
	gcc -c main.c -g
rotozoom.o:rotozoom.c
	gcc -c rotozoom.c -g 


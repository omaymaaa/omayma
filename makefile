prog:main.o AI2.o 
	gcc   main.o AI2.o -o prog -lSDL -lSDL_image -lm
main.o:main.c
	gcc -c main.c -g

AI2.o:AI2.c
	gcc -c AI2.c -g 


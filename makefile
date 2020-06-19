prog:main.o enigf.o 
	gcc   main.o enigf.o -o prog -lSDL -lSDL_image
main.o:main.c
	gcc -c main.c -g

enigf.o:enigf.c
	gcc -c enigf.c -g 



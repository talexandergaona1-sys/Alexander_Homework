all: mandelbrot_main

mandelbrot_functions.o: mandelbrot_functions.cc mandelbrot_header.h
	g++ -c -Wall -Werror mandelbrot_functions.cc

mandelbrot_main.o: mandelbrot_main.cc mandelbrot_header.h
	g++ -c -Wall -Werror mandelbrot_main.cc

mandelbrot_main: mandelbrot_main.o mandelbrot_functions.o
	g++ -o mandelbrot_main mandelbrot_main.o mandelbrot_functions.o
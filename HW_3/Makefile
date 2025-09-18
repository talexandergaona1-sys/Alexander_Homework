all: mandelbrot3_main

mandelbrot3_functions.o: mandelbrot3_functions.cc mandelbrot3_header.h
	g++ -c -Wall -Werror mandelbrot3_functions.cc

mandelbrot3_main.o: mandelbrot3_main.cc mandelbrot3_header.h
	g++ -c -Wall -Werror mandelbrot3_main.cc

mandelbrot3_main: mandelbrot3_main.o mandelbrot3_functions.o
	g++ -o mandelbrot3_main mandelbrot3_main.o mandelbrot3_functions.o
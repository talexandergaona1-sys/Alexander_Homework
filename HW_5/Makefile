all: mandelbrot_PPM_main

mandelbrot_PPM_functions.o: mandelbrot_PPM_functions.cc mandelbrot_PPM_header.h
	g++ -c -Wall -Werror mandelbrot_PPM_functions.cc

mandelbrot_PPM_main.o: mandelbrot_PPM_main.cc mandelbrot_PPM_header.h
	g++ -c -Wall -Werror mandelbrot_PPM_main.cc

mandelbrot_PPM_main: mandelbrot_PPM_main.o mandelbrot_PPM_functions.o
	g++ -o mandelbrot_PPM_main mandelbrot_PPM_main.o mandelbrot_PPM_functions.o
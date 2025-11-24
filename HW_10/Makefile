all: TextGen_Main

Generator.o: Generator.cc Generator.h Pattern.h
	g++ -c -Wall -Werror Generator.cc

TextGen_Main.o: TextGen_Main.cc Generator.h Pattern.h
	g++ -c -Wall -Werror TextGen_Main.cc

TextGen_Main: TextGen_Main.o Generator.o
	g++ -o TextGen_Main TextGen_Main.o Generator.o
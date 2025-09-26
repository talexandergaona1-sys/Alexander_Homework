all: PPM_Main

PPM_Functions.o: PPM_Functions.cc PPM_Header.h
	g++ -c -Wall -Werror PPM_Functions.cc

PPM_Main.o: PPM_Main.cc PPM_Header.h
	g++ -c -Wall -Werror PPM_Main.cc

PPM_Main: PPM_Main.o PPM_Functions.o
	g++ -o PPM_Main PPM_Main.o PPM_Functions.o
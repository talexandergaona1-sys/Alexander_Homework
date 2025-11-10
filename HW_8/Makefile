all: Book_Main

Exercise.o: Exercise.cc Exercise.h
	g++ -c -Wall -Werror Exercise.cc

Book.o: Book.cc Book.h Exercise.h
	g++ -c -Wall -Werror Book.cc

Main.o: Main.cc Book.h Exercise.h
	g++ -c -Wall -Werror Main.cc

Book_Main: Main.o Book.o Exercise.o
	g++ -o Book_Main Main.o Book.o Exercise.o
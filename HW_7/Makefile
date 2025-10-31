all: Image_Main

Image_Functions.o: Image_Functions.cc Image_Header.h
	g++ -c -Wall -Werror Image_Functions.cc -I"C:/msys64/mingw64/include"

Image_Main.o: Image_Main.cc Image_Header.h
	g++ -c -Wall -Werror Image_Main.cc -I"C:/msys64/mingw64/include"

Image_Main: Image_Main.o Image_Functions.o
	g++ -o Image_Main Image_Main.o Image_Functions.o -L"C:/msys64/mingw64/lib"

clean:
	del Image_Main.o Image_Functions.o Image_Main.exe
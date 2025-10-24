all: JPEG_Converter_Main

JPEG_Converter_Functions.o: JPEG_Converter_Functions.cc JPEG_Converter_Header.h
	g++ -c -Wall -Werror JPEG_Converter_Functions.cc -I"C:/msys64/mingw64/include"

JPEG_Converter_Main.o: JPEG_Converter_Main.cc JPEG_Converter_Header.h
	g++ -c -Wall -Werror JPEG_Converter_Main.cc -I"C:/msys64/mingw64/include"

JPEG_Converter_Main: JPEG_Converter_Main.o JPEG_Converter_Functions.o
	g++ -o JPEG_Converter_Main JPEG_Converter_Main.o JPEG_Converter_Functions.o -L"C:/msys64/mingw64/lib" -ljpeg

clean:
	del JPEG_Converter_Main.o JPEG_Converter_Functions.o JPEG_Converter_Main.exe


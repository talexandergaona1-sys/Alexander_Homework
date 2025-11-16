all: FileStreamBuf_Main

FileStreamBuf_Functions.o: FileStreamBuf_Functions.cc FileStreamBuf.h
	g++ -c -Wall -Werror FileStreamBuf_Functions.cc

FileStreamBuf_Main.o: FileStreamBuf_Main.cc FileStreamBuf.h
	g++ -c -Wall -Werror FileStreamBuf_Main.cc

FileStreamBuf_Main: FileStreamBuf_Main.o FileStreamBuf_Functions.o
	g++ -o FileStreamBuf_Main FileStreamBuf_Main.o FileStreamBuf_Functions.o
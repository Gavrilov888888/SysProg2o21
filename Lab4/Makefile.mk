all: AbsoluteTime.exe

Local_time.o: AbsoluteTime.c
	gcc -c AbsoluteTime.c -o AbsoluteTime.o

Local_time.exe: AbsoluteTime.o
	gcc AbsoluteTime.o -o AbsoluteTime.exe

a.exe: rock-paper-scissors.o
	gcc rock-paper-scissors.o -o a.exe

rock-paper-scissors.o: rock-paper-scissors.c
	gcc -c rock-paper-scissors.c -o rock-paper-scissors.o
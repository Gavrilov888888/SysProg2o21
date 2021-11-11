All: progA.exe progB.exe

progA.o: progA.c
	gcc -c progA.c -o progA.o

progA.exe: progA.o
	gcc progA.o -o progA.exe

progB.o: progB.c
	gcc -c progB.c -o progB.o

progB.exe: progB.o
	gcc progB.o -o progB.exe
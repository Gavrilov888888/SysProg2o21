lab3: progA.exe progB.exe

progB.exe: progB.o
	gcc progB.o -o progB.exe

progB.o: progB.c
	gcc -c progB.c -o progB.o

progA.exe: progA.o
	gcc progA.o -o progA.exe

progA.o: progA.c
	gcc -c progA.c -o progA.o
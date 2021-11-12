#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rps.h>

char getCPUMove(void) {
	srand(time(0));
	
	//Random number from 1 to 3
	int num = rand() % 3 +1;
	
	if(num==1) return 'r';
	if(num==2) return 'p';
	if(num==3) return 's';
}

char getUserMove(void) {
	char tmp;
	printf("Rock, Paper, Scissors. Let's begin!\n");
	printf("-----------Choose one--------------\n");
	printf("(r) for rock\n");
	printf("(p) for paper\n");
	printf("(s) for scissors\n");
	tmp = getchar();
	
	while (tmp != 'r' && tmp != 'p' && tmp != 's'){
		printf("-----------Choose one--------------\n");
		printf("(r) for rock\n");
		printf("(p) for paper\n");
		printf("(s) for scissors\n");
		tmp = getchar();
	}
	
	return tmp;
}

void selectMove (char c) {
	if (c == 'r') printf("Rock");
    if (c == 'p') printf("Paper");
    if (c == 's') printf("Scissors");
}

void compareMoves(char uc, char cc) {
	if (uc == 'r' && cc == 'p') {
        printf("\nPaper beats Rock. You Lose!");
    }
    else if (uc == 'p' && cc == 's') {
        printf("\nScissors beats Paper. You Lose!");
    }
    else if (uc == 's' && cc == 'r') {
        printf("\nRock beats Scissors. You Lose!");
    }
    
	else if (uc == 'r' && cc == 's') {
        printf("\nRock beats Scissors. You Win!");     
    }
    else if (uc == 'p' && cc == 'r') {
        printf("\nPaper beats Rock. You Win!");       
    }
    else if (uc == 's' && cc == 'p') {
        printf("\nScissors beats Paper. You Win!");  
    }
    else{
        printf("\nIt's a Tie. Try again");
    }
}

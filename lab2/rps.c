#include <rps.h>
#include <stdio.h>

int main() {
	//User's choice
	char uC; 
	//Compter's choice
	char cC;
    uC = getUserMove();
    printf("You chose: ");
    selectMove(uC);
    
    cC = getCPUMove();
	printf("\nComputer chose: ");
    selectMove(cC);
    
    compareMoves(uC, cC);
 
    return 0;
}
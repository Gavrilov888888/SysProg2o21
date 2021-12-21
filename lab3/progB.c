#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function for counting letters (both lowercase and uppercase), if lowercase char c placed
int count(char str[], char c){
	
	int cnt = 0;
	
	for(int i = 0; i < strlen(str); i++){
		if (str[i] == c || str[i] == c-32){
			cnt++;
		}
	}

	return cnt;
}

int main() {
	
	//Opening our file for reading
	FILE *fp = fopen("text.txt", "r");
  
	//Reading all of the letters and putting them into array, like in progA
	char line [1024];
	fgets(line, 1024, fp);
	
	printf("In line ");
	puts(line);
	printf("---------------------------------------------------------\n");
	
	//Begin letter evaluation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	double perc;
	int total = strlen(line);
  
	int cA = count(line, 'a');
	perc = 100.0 * cA/total;
	printf("Letter 'a' was found %d time(s), which is %.2f %% of a file\n", cA, perc);
	
	int cB = count(line, 'b');
	perc = 100.0 * cB/total;
	printf("\nLetter 'b' was found %d time(s), which is %.2f %% of a file\n", cB, perc);
	
	int cC = count(line, 'c');
	perc = 100.0 * cC/total;
	printf("\nLetter 'c' was found %d time(s), which is %.2f %% of a file\n", cC, perc);
	
	int cD = count(line, 'd');
	perc = 100.0 * cD/total;
	printf("\nLetter 'd' was found %d time(s), which is %.2f %% of a file\n", cD, perc);
	
	int cE = count(line, 'e');
	perc = 100.0 * cE/total;
	printf("\nLetter 'e' was found %d time(s), which is %.2f %% of a file\n", cE, perc);
	
	int cF = count(line, 'f');
	perc = 100.0 * cF/total;
	printf("\nLetter 'f' was found %d time(s), which is %.2f %% of a file\n", cF, perc);
	
	int cG = count(line, 'g');
	perc = 100.0 * cG/total;
	printf("\nLetter 'g' was found %d time(s), which is %.2f %% of a file\n", cG, perc);
	
	int cH = count(line, 'h');
	perc = 100.0 * cH/total;
	printf("\nLetter 'h' was found %d time(s), which is %.2f %% of a file\n", cH, perc);
	
	int cI = count(line, 'i');
	perc = 100.0 * cI/total;
	printf("\nLetter 'i' was found %d time(s), which is %.2f %% of a file\n", cI, perc);
	
	int cJ = count(line, 'j');
	perc = 100.0 * cJ/total;
	printf("\nLetter 'j' was found %d time(s), which is %.2f %% of a file\n", cJ, perc);
	
	int cK = count(line, 'k');
	perc = 100.0 * cK/total;
	printf("\nLetter 'k' was found %d time(s), which is %.2f %% of a file\n", cK, perc);
	
	int cL = count(line, 'l');
	perc = 100.0 * cL/total;
	printf("\nLetter 'l' was found %d time(s), which is %.2f %% of a file\n", cL, perc);
	
	int cM = count(line, 'm');
	perc = 100.0 * cM/total;
	printf("\nLetter 'm' was found %d time(s), which is %.2f %% of a file\n", cM, perc);
	
	int cN = count(line, 'n');
	perc = 100.0 * cN/total;
	printf("\nLetter 'n' was found %d time(s), which is %.2f %% of a file\n", cN, perc);
	
	int cO = count(line, 'o');
	perc = 100.0 * cO/total;
	printf("\nLetter 'o' was found %d time(s), which is %.2f %% of a file\n", cO, perc);
	
	int cP = count(line, 'p');
	perc = 100.0 * cP/total;
	printf("\nLetter 'p' was found %d time(s), which is %.2f %% of a file\n", cP, perc);
	
	int cQ = count(line, 'q');
	perc = 100.0 * cQ/total;
	printf("\nLetter 'q' was found %d time(s), which is %.2f %% of a file\n", cQ, perc);
	
	int cR = count(line, 'r');
	perc = 100.0 * cR/total;
	printf("\nLetter 'r' was found %d time(s), which is %.2f %% of a file\n", cR, perc);
	
	int cS = count(line, 's');
	perc = 100.0 * cS/total;
	printf("\nLetter 's' was found %d time(s), which is %.2f %% of a file\n", cS, perc);
	
	int cT = count(line, 't');
	perc = 100.0 * cT/total;
	printf("\nLetter 't' was found %d time(s), which is %.2f %% of a file\n", cT, perc);
	
	int cU = count(line, 'u');
	perc = 100.0 * cU/total;
	printf("\nLetter 'u' was found %d time(s), which is %.2f %% of a file\n", cU, perc);
	
	int cV = count(line, 'v');
	perc = 100.0 * cV/total;
	printf("\nLetter 'v' was found %d time(s), which is %.2f %% of a file\n", cV, perc);
	
	int cW = count(line, 'w');
	perc = 100.0 * cW/total;
	printf("\nLetter 'w' was found %d time(s), which is %.2f %% of a file\n", cW, perc);
	
	int cX = count(line, 'x');
	perc = 100.0 * cX/total;
	printf("\nLetter 'x' was found %d time(s), which is %.2f %% of a file\n", cX, perc);
	
	int cY = count(line, 'y');
	perc = 100.0 * cY/total;
	printf("\nLetter 'y' was found %d time(s), which is %.2f %% of a file\n", cY, perc);
	
	int cZ = count(line, 'z');
	perc = 100.0 * cZ/total;
	printf("\nLetter 'z' was found %d time(s), which is %.2f %% of a file\n", cZ, perc);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	printf("---------------------------------------------------------\n");
	//Closing file
	fclose(fp);
  
	return 0;
}

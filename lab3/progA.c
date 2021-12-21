#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	//Reading string with a variable length from console
	char line [1024];								//1024 characters shoud be enough for current task
	
	printf("Enter a string: ");
	scanf("%1023[^\n]", line); 						//safe way to read, without causing buffer overflow
	
	//Making a file
	FILE *fp;
	fp = fopen("text.txt", "w");
	
	//Allocating memory for an array, that we will fill later
	char *eline;
	eline = (char*) malloc(strlen(line)-1);	
	
	//Checking for only latin alphabet letters
	char l = 0;
	int count = 0;
	for (int i = 0; i < strlen(line); i++) {
		l = line[i];
		if ((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z')) {
			eline[count] = line[i];
			count++;
		}
	}
	
	//Simple bubble sort
	int i, j;
	bool swpd;
	for (i = 0; i < strlen(eline) - 1; i++) {
		swpd = false;
		for (j = 0; j < strlen(eline)-i-1; j++) {
			if (eline[j] > eline[j+1]) {
				int temp = eline[j];
				eline[j] = eline[j+1];
				eline[j+1] = temp;
				swpd = true;
			}
		}
		if (swpd == false){
			break;
		}
	}	
	puts(eline); //Show the result of sort
	
	fputs(eline, fp); //Writing array into file
	//Closing the file, reallocating memory
	fclose(fp);
	free(eline);
	
	return 0;
}

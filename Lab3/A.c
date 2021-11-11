#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char string[100];
	printf("Enter something: ");

	fgets(string, 100, stdin);

	FILE *fp = fopen("test.txt", "w");

	int character, charIndex = 0;

	char *stringPointer = (char*) malloc (strlen(string)-1);	

	for (int counter = 0; counter < strlen(string); counter++)
	{
		character = string[counter];
		if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
		{
			stringPointer[charIndex] = string[counter];
			charIndex++;

		}
	}

	puts(stringPointer);

	for (int externalCounter = 0; externalCounter < strlen(stringPointer) - 1; externalCounter++)
	{

		for (int internalCounter = 0; internalCounter < strlen(stringPointer)- externalCounter -1; internalCounter++)
		{

			if (stringPointer[internalCounter] > stringPointer[internalCounter+1])
			{
				char tmp = stringPointer[internalCounter];
				stringPointer[internalCounter] = stringPointer[internalCounter+1];
				stringPointer[internalCounter+1] = tmp;
			}

		}

	}
	puts(stringPointer);
	fputs(stringPointer, fp);
	fclose(fp);
	free(stringPointer);

	return 0;
}
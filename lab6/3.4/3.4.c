#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int func(char* str)
{
	char buf[256] = { 0 };
	char name[100];
	char* text;
	char* token;
	int counter = 0;
	strcpy(name, "/proc/");
	strcat(name, str);
	strcat(name, "/task/");
	strcat(name, str);
	strcat(name, "/children");
	FILE *fp = fopen(name, "r");
	fgets(buf, 256, fp);
	fclose(fp);
	text = buf;
	if (strcmp(buf, "") == 0)
	{
		return 0;
	}
	else
	{
		token = strtok_r(text, " ", &text);
		if (token)
		{
			counter += func(token);
			do {
			token = strtok_r(text, " ", &text);
			counter++;
			if (token)
				counter += func(token);
			} while (token);
		}
	}
	return counter;
}

int main(int argc, char* argv[])
{
	printf("%d\n", func(argv[1]) + 1);
	return 0;

}
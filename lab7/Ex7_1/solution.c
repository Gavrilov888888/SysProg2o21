#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char buf[100];
	sprintf(buf, "%s %s", argv[1], argv[2]);
	FILE *stream;
	if ((stream = popen(buf, "r")) == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	char ch;
	int kol = 0;
	while ((ch = fgetc(stream)) != EOF)
	{
		if (ch == '0')
		{
			kol++;
		}
	}
	printf("%d\n", kol);
	pclose(stream);
	return 0;
}

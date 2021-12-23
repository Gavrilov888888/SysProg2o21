#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pid = fork();
	if (pid == 0)
	{
		setsid();
		chdir("/");
		printf("%d\n", getppid());
		fclose(stdin);
		fclose(stdout);
		fclose(stderr);
		sleep(10000);
		exit(0);
	} else if (pid == -1)
	{
		printf("Error\n");
	} 
	return 0;

}
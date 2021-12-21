#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int selectno)
{
	//raise(SIGTERM);
	exit(0);
}

int main()
{
	pid_t pid = fork();
	int i = 0;
	
	if (pid == 0)
	{
		setsid();
		chdir("/");
		printf("%d\n", getpid());
		signal(SIGURG, my_handler);
		while (1)
		{
        		/*printf("Hello\n");
        		printf("PID: %d, Ppid: %d\n", getpid(), getppid());
        		usleep(500000);
			if (i == 2)
			{
				signal(SIGURG, my_handler);
				printf("TUT\n");
				break;
			}
			i++;*/
		}
		fclose(stdin);
		fclose(stdout);
		fclose(stderr);
	} else if (pid == -1)
	{
		printf("Error\n");
	}
	return 0;
}

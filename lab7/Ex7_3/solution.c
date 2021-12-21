#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count1 = 0, count2 = 0, f = 0;

void mysignal_handler(int signalno)
{
	if (signalno == SIGUSR1)
		count1++;
	if (signalno == SIGUSR2)
		count2++;
}

void my_handler(int signalno)
{
	printf("%d %d\n", count1, count2);
	f++;
}

int main()
{
	int count1 = 0, count2 = 0;
	signal(SIGUSR1, mysignal_handler);
	signal(SIGUSR2, mysignal_handler);
	signal(SIGTERM, my_handler);
	while(1)
	{
		/*signal(SIGUSR1, mysignal_handler);
		signal(SIGUSR2, mysignal_handler);
		signal(SIGTERM, mysignal_handler);*/
		if (f > 0)
			break;
	}
	return 0;
}

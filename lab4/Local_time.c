#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main()
{
	long int ltime;
    clock_t start, end;
    struct timeval tv;
	struct tm* ptm;
    struct timespec ts;
	char str[50];
    start = clock();
	ltime = time(NULL);
	printf("Time via time(): \t\t%s", ctime(&ltime));
    end = clock();
    printf("Process time: %ld\n", (end - start)/_SC_CLK_TCK);
    start = clock();
	gettimeofday(&tv, NULL);
	ptm = localtime(&tv.tv_sec);
	strftime(str, sizeof(str), "%a %b %d %X %Y", ptm);
	printf("Time via gettimeofday(): \t%s\n", str);
    end = clock();
    printf("Process time: %ld\n", (end - start)/_SC_CLK_TCK);
    start = clock();
	clock_gettime(CLOCK_REALTIME, &ts);
	printf("Time via clock_gettime(): \t%s", ctime(&ts.tv_sec));
    end = clock();
    printf("Process time: %ld\n", (end - start)/_SC_CLK_TCK);
	return 0;
}

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main() {

  // Using time() function to get system time
  time_t mytime;

  clock_t tik = clock();
  time(&mytime);
  printf("System time, using time(): \t\t%s", ctime(&mytime));
  clock_t tok = clock();
  printf("Process time: %ld\n",
         (tok - tik) /
             _SC_CLK_TCK); // Process time in number of clock ticks per second


  // Using gettimeofday() function to get system time
  struct timeval tv;
  struct tm *timeinfo;
  char buffer[64];

  tik = clock();
  gettimeofday(&tv, NULL);
  timeinfo = localtime(&tv.tv_sec);
  strftime(buffer, sizeof(buffer), "%a %b %d %X %Y", timeinfo);
  printf("System time, using gettimeofday(): \t%s\n", buffer);
  tok = clock();
  printf("Process time: %ld\n", 
         (tok - tik) / 
             _SC_CLK_TCK); // Process time in number of clock ticks per second


  // Using clock_gettime() function to get system time
  struct timespec tsp;

  tik = clock();
  clock_gettime(CLOCK_REALTIME, &tsp);
  printf("System time, using clock_gettime(): \t%s", ctime(&tsp.tv_sec));
  tok = clock();
  printf("Process time: %ld\n", 
		 (tok - tik) / 
			 _SC_CLK_TCK); // Process time in number of clock ticks per second
  return 0;
}

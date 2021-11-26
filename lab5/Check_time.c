#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int power(int y, int x) {
  int i;
  unsigned long long int a = 1;
  for (i = 0; i < x; i++) {
    a *= y;
  }
  return a;
}

int main() {
  struct timespec ts1, ts2, ts3, ts4;
  long int process_time;
  int x;
  int *mas;
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)malloc(power(2, x));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (mas == NULL) {
      perror("malloc");
    } else {
      printf("Time of malloc 2^x (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of malloc 2^x (in nanoseconds): %ld\n\n", process_time);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)malloc(power(2, (x + 1)));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      perror("malloc");
    } else {
      printf("Time of malloc 2^(x+1) (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of malloc 2^(x+1) (in nanoseconds): %ld\n\n", process_time);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)calloc(power(2, x), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      perror("calloc");
    } else {
      printf("Time of calloc 2^x (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of calloc 2^x (in nanoseconds): %ld\n\n", process_time);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)calloc(power(2, (x + 1)), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      perror("calloc");
    } else {
      printf("Time of calloc 2^(x+1) (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of calloc 2^(x+1) (in nanoseconds): %ld\n\n", process_time);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)alloca(power(2, x) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      perror("alloca");
    } else {
      printf("Time of alloca 2^x (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of alloca 2^x (in nanoseconds): %ld\n", process_time);
  free(mas);
  clock_gettime(CLOCK_REALTIME, &ts1);
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)alloca(power(2, (x + 1)) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    process_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      perror("alloca");
    } else {
      printf("Time of alloca 2^(x+1) (in nanoseconds): %ld\n", process_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  process_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("\nTime of alloca 2^(x+1) (in nanoseconds): %ld\n", process_time);
  free(mas);
  return 0;
}
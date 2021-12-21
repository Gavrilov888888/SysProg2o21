#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  struct timespec ts1, ts2, ts3, ts4;
  long int my_time;
  int x;
  int *mas;

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For malloc(2^x)=================
  printf("==================For malloc(2^x)=================\n");
  for (x = 0; x < 64; x++) {

    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)malloc(pow(2, x));
    clock_gettime(CLOCK_REALTIME, &ts4);

    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);

    if (!mas) {
      printf("ERROR: Null malloc operation\n");
    } else {
      printf("Time of malloc 2^x: %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For malloc(2^(x+1))=================
  printf("==================For malloc(2^(x+1))=================\n");
  for (x = 0; x < 64; x++) {

    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)malloc(pow(2, (x + 1)));
    clock_gettime(CLOCK_REALTIME, &ts4);

    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);

    if (!mas) {
      printf("ERROR: Null malloc operation\n");
    } else {
      printf("Time of malloc 2^(x+1) : %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For calloc(2^x)=================
  printf("==================For calloc(2^x)=================\n");
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)calloc(pow(2, x), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      printf("ERROR: Null calloc operation\n");
    } else {
      printf("Time of calloc 2^x : %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For calloc(2^(x+1))=================
  printf("==================For calloc(2^(x+1))=================\n");
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)calloc(pow(2, (x + 1)), sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      printf("ERROR: Null calloc operation\n");
    } else {
      printf("Time of calloc 2^(x+1) : %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For alloca(2^x)=================
  printf("==================For alloca(2^x)=================\n");
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)alloca(pow(2, x) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      printf("ERROR: Null alloca operation\n");
    } else {
      printf("Time of alloca 2^x : %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  clock_gettime(CLOCK_REALTIME, &ts1);

  //==================For alloca(2^(x+1))=================
  printf("==================For alloca(2^(x+1))=================\n");
  for (x = 0; x < 64; x++) {
    clock_gettime(CLOCK_REALTIME, &ts3);
    mas = (int *)alloca(pow(2, (x + 1)) * sizeof(int));
    clock_gettime(CLOCK_REALTIME, &ts4);
    my_time = (ts4.tv_sec - ts3.tv_sec) + (ts4.tv_nsec - ts3.tv_nsec);
    if (!mas) {
      printf("ERROR: Null alloca operation\n");
    } else {
      printf("Time of alloca 2^(x+1) : %ld ns\n", my_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &ts2);
  my_time = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec);
  printf("==================================================\n");
  printf("Total time: %ld ns\n", my_time);
  free(mas);
  printf("==================================================\n\n");
  //==================================================

  return 0;
}

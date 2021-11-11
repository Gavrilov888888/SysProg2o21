#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *fp = fopen("task.txt", "r");
  char arr[100];

  fgets(arr, 100, fp);
  puts(arr);
  int n = strlen(arr);
  printf("Number of characters:\n");
  for (int externalCounter = 0; externalCounter < n; externalCounter++) {
    int character = 0;

    for (int internalCounter = 0; internalCounter < n; internalCounter++) {

      if (arr[internalCounter] == arr[externalCounter]) {
        character++;
      }

    }
    printf("\t%c: %d\n", arr[externalCounter], character);

    while (arr[externalCounter + 1] == arr[externalCounter]) {
      externalCounter++;
    }
  }
  fclose(fp);
  return 0;
}
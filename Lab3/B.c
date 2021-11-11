#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  FILE *fp = fopen("test.txt", "r");
  char string[100];

  fgets(string, 100, fp);
  puts(string);
  int n = strlen(string);
  printf("Number of characters:\n");
  for (int externalCounter = 0; externalCounter < n; externalCounter++) {
    int character = 0;

    for (int internalCounter = 0; internalCounter < n; internalCounter++) {

      if (string[internalCounter] == string[externalCounter]) {
        character++;
      }

    }
    printf("\t%c: %d\n", string[externalCounter], character);

    while (string[externalCounter + 1] == string[externalCounter]) {
      externalCounter++;
    }
  }
  fclose(fp);
  return 0;
}
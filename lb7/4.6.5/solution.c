#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    int shmid1, shmid2, shmid3;
    int *num1, *num2, *num3, *np1, *np2, *np3;
    int n;
    key_t key;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <shmid1> <shmid2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    shmid1 = strtol(argv[1], NULL, 10);
    shmid2 = strtol(argv[2], NULL, 10);
    key = ftok("/etc/hosts", 1);

    if ((shmid1 = shmget(shmid1, 1000, 0)) == -1)
    {
        perror("shmget1");
        exit(EXIT_FAILURE);
    }

    if ((shmid2 = shmget(shmid2, 1000, 0)) == -1)
    {
        perror("shmget2");
        exit(EXIT_FAILURE);
    }

    if ((shmid3 = shmget(key, 1000,
            S_IRUSR | S_IWUSR | IPC_CREAT)) == -1)
    {
        perror("shmget3");
        exit(EXIT_FAILURE);
    }

    if ((num1 = (int *) shmat(shmid1, NULL, 0)) == (int *) -1) 
    {
        perror("shmat1");
        exit(EXIT_FAILURE);
    }
    if ((num2 = (int *) shmat(shmid2, NULL, 0)) == (int *) -1) 
    {
        perror("shmat2");
        exit(EXIT_FAILURE);
    }
    if ((num3 = (int *) shmat(shmid3, NULL, 0)) == (int *) -1) 
    {
        perror("shmat3");
        exit(EXIT_FAILURE);
    }

    np1 = num1;
    np2 = num2;
    np3 = num3;

    for (n = 0; n < 100; n++)
    {
        *np3 = *np1 + *np2;
        np1++; np2++; np3++;
    }

    if (shmdt(num1) == -1)
    {
        perror("shmdt1");
        exit(EXIT_FAILURE);
    }
    if (shmdt(num2) == -1)
    {
        perror("shmdt2");
        exit(EXIT_FAILURE);
    }
    if (shmdt(num3) == -1)
    {
        perror("shmdt3");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", key);

    return 0;
}

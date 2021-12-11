#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main()
{
	pid_t pid = getpid();
	char buf[256] = { 0 };
	sprintf(buf, "/proc/%d/status", pid);

	FILE *fp = fopen(buf, "r");
	if (!fp)
	{
		printf("Error\n");
	}

	const char *str_id = "ppid:\t";

	const int str_id_len = strlen(str_id);

	while(fgets(buf, sizeof(buf) - 1, fp)) {
		if (!strncasecmp(str_id, buf, str_id_len)) {
			sscanf(buf + str_id_len, "%s", buf);
			printf("%s", buf + str_id_len);
		}
	}
	return 0;
}

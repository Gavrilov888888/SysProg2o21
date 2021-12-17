#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int func(char* str)
{
	char buf[256] = { 0 };
	sprintf(buf, "/proc/%d/status", atoi(str));
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
			break;
          	}
  	}
	if (atoi(buf + str_id_len) != 1)
		return func(buf + str_id_len);
  	else return atoi(buf + str_id_len);
}

int main(int argc, char* argv[])
{
	printf("%s\n", argv[1]);
	func(argv[1]);
	return 0;
}

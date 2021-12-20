#include <stdio.h>


int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        char command[128];
        snprintf(command, sizeof(command), "./%s %s", argv[1], argv[2]);
        FILE* pipe = popen(command, "r");
        if (pipe != NULL)
        {            
            int count = 0;
            int chr = getc(pipe);
            for ( ; chr != EOF; chr = getc(pipe))
            {
                if (chr == '0')
                {
                    count++;
                }
            }
            pclose(pipe);
            printf("%d\n", count);
        }      
    }   
    return 0;
}

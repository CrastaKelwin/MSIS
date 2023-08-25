#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char ch = 'A';
    int use_lib = 0;
    int to_lower = 1;
    if (argc < 3)
    {
        printf("Run this with Arguements [input_file] [lower|upper] [lib(optional)]\n");
        exit(-1);
    }
    fp1 = fopen(argv[1], "r");
    if (fp1 == 0)
    {
        printf("unable to open file %s\nTerminating the process\n", argv[1]);
        exit(-1);
    }
    fp2 = fopen("result.text", "w");
    if (fp2 == 0)
    {
        printf("unable to open file %s\nTerminating the process\n", argv[1]);
        exit(-1);
    }

    if (strcmp("upper", argv[2]) == 0)
    {
        printf("converting %s file contents to upper case\n", argv[1]);
        to_lower = 0;
    }
    else if (strcmp("lower", argv[2]) == 0)
    {

        printf("converting %s file contents to lower case\n", argv[1]);
        to_lower = 1;
    }
    else
    {
        printf("Run this with Arguements [input_file] [lower|upper] [lib(optional)]\n");
        exit(-1);
    }

    if (argc == 4 && strcmp("lib", argv[3]) == 0)
    {
        printf("using lib\n");
        use_lib = 1;
    }

    while ((ch = getc(fp1)) != EOF)
    {
        if (use_lib == 1)
        {
            if (to_lower)
                ch = tolower(ch);
            else
                ch = toupper(ch);
        }
        else
        {
            if (to_lower)
            {
                if ((ch <= 'Z') && (ch >= 'A'))
                {
                    ch = ch - 'A' + 'a';
                }
            }
            else
            {
                if ((ch <= 'z') && (ch >= 'a'))
                {
                    ch = ch - 'a' + 'A';
                }
            }
        }
        putc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
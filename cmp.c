#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{    
    FILE *file1, *file2;
    int printResult = 0, ignoreCapitalLower = 0;
    int ch1, ch2, result = 0, equal = 1;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: cmp [-v] [-i] file1 file2\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-v"))
        {
            printResult = 1;
        }
        if (!strcmp(argv[i], "-i"))
        {
            ignoreCapitalLower = 1;
        }
    }

    file1 = fopen(argv[1], "rb");
    if (file1 == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    file2 = fopen(argv[2], "rb");
    if (file2 == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[2]);
        exit(1);
    }

    while (1)
    {
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);

        if (ch1 == EOF || ch2 == EOF)
        {
            if (ch1 != ch2)
            {
                equal = 0;
                break;
            }
            break;
        }

        if (ignoreCapitalLower)
        {
            ch1 = tolower(ch1);
            ch2 = tolower(ch2);
        }

        if (ch1 != ch2)
        {
            equal = 0;
            break;
        }
    }

    if (!equal)
    {
        result = 1;
    }

    if (printResult)
    {
        if (equal)
        {
            printf("equal\n");
        }
        else
        {
            printf("distinct\n");
        }
    }

    fclose(file1);
    fclose(file2);

    return result;
}

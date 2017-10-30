/**FILE SEARCH**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    /*Check if input is ehough*/
    if (argc < 3) {
        printf("Error. Not enough data.");
        return -1;
    }

    int i; /*String counter*/
    char localstr[256]; /*Every string of file will be put here*/
    char *chars; /*Pointer to the found substring*/
    FILE *fp;

    i = 1;

    if ((fp = fopen(argv[1], "r")) == NULL) { /*If fopen() returns NULL, file is either absent or protected from reading*/
        printf("Error. No such file or file cannot be read.\n");
        return -1;
    }
    while(fgets(localstr, 256, fp) != NULL) { /*If fgets() returns NULL, EOF is reached*/
        if ((chars = strstr(localstr, argv[2])) != NULL) { /*Look for a substring argv[2] in the string localstr*/
          printf("%d:%d %s\n", i, (int)(chars - localstr + 1), argv[2]);
          return 1;
        } else {
            i++; /*Switch to the next string*/
        }
    }

    printf("Sorry. Nothing found in this file:(\n");
    return -1;

    printf("Hello world!\n");
    return 0;
}

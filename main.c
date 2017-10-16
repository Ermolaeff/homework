#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    float number = 0;
    char scale = ' ';

    if (argc == 1) {
        printf("Missing data...");
        return -1;
    } else if (argc == 2) {
        number = atof(argv[1]);
        if (number < -273.15) {
            printf("The data you entered is less than absolute null.");
            return -1;
        } else {
        printf("%.2f C:\n%.2f F\n%.2f K\n\n%.2f F:\n%.2f C\n%.2f K\n\n%.2f K:\n%.2f C\n%.2f F\n", number, number * 9 / 5 + 32,
               number + 273.15, number, (number - 32) / 1.8,
               (number + 459.67) / 1.8, number, number - 273.15, number *1.8 - 459.67);
        return 1;
        }
    } else {
        number = atof(argv[1]);
        if (isalpha(*argv[2]) == 0) {
            printf("Invalid data...");
            return -1;
        } else {
            scale = toupper(*argv[2]);
        }

        switch(scale) {
        case 'C':
            if (number >= -273.15) {
                printf("%.2f F\n%.2f K\n", number * 1.8 + 32, number + 273.15);
            } else {
                printf("The number is less than absolute null.");
                return -1;
            }
                break;
        case 'F':
            if (number > -459.67) {
                printf("%.2f C\n%.2f K\n", (number - 32) / 1.8, (number + 459.67) / 1.8);
             } else {
                printf("The number is less than absolute null.");
                return -1;
            }
             break;
        case 'K':
            if (number >= 0) {
                printf("%.2f C\n%.2f F\n", number -273.15, number * 1.8 - 459.67);
            } else {
                printf("The number is less than absolute null.");
                return -1;
            }
                break;
        default:
            printf("Unknown scale...");
            return -1;
        }

        return 1;
    }
}

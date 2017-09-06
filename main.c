#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    float count;
    char name;

    scanf("%f%*c%c", &count, &name);

    switch (name) {
    case 'C':
        printf("%.2f F\n", count * 1.8 + 32);
        printf("%.2f K\n", count + 273.15);
        getch();

        break;
    case 'F':
        printf("%.2f C\n", (count - 32) / 1.8);
        printf("%.2f K\n", (count + 459.67)*5/9);
        getch();

        break;
    case 'K':
        printf("%.2f C\n", count + 273.15);
        printf("%.2f F\n", count * 9/5-459.67);
        getch();

        break;
    default:
        printf("%.2f C:\n", count);
        printf("%.2f F\n", count * 1.8 + 32);
        printf("%.2f K\n\n", count + 273.15);

        printf("%.2f F:\n", count);
        printf("%.2f C\n", (count - 32) / 1.8);
        printf("%.2f K\n\n", (count + 459.67)*5/9);

        printf("%.2f K:\n", count);
        printf("%.2f C\n", count + 273.15);
        printf("%.2f F\n\n", count * 9/5-459.67);
        getch();

        break;
    }

    return 0;
}

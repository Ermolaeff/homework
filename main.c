#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>

int input(float*, char*);
void output(float*, char*);

int main()
{
    char scale;
    float value;

    setlocale(LC_ALL, "rus");

    if(input(&value, &scale) == 0)
    {
        printf("Ошибка ввода...");
        return 0;
    } else {
        output(&value, &scale);
    }

    return 1;
}

//Функция для ввода и проверки чисел и шкалы

int input(float *value, char *scale)
{
    scanf("%f", &(*value));
    *scale = getch();

    if (isalpha(*scale) != 0)
        *scale = toupper(*scale);
    else if (*scale == 0x0D)
        return 1;
    else
        return 0;

    if ((*scale == 'C' && *value < -273.15) || (*scale == 'K' && *value < 0) || (*scale == 'F' && *value < -459.67))
        return 0;

        return 1;
}


//функция вывода

void output(float *value, char *scale) {
    if (*scale == 0x0D)
        printf("%.2f C:\n%.2f F\n%.2f K\n\n%.2f F:\n%.2f C\n%.2f K\n\n%.2f K:\n%.2f C\n%.2f F\n", *value, *value * 9 / 5 + 32, *value + 273.15, *value, (*value - 32) / 1.8, (*value + 459.67) / 1.8,
               *value, *value - 273.15, *value *1.8 - 459.67);

    switch(*scale) {
    case 'C':
        printf("%.2f F\n%.2f K\n", *value * 1.8 + 32, *value + 273.15);
        break;
    case 'F':
        printf("%.2f C\n%.2f K\n", (*value - 32) / 1.8, (*value + 459.67) / 1.8);
        break;
    case 'K':
        printf("%.2f C\n%.2f F\n", *value -273.15, *value * 1.8 - 459.67);
        break;
    default:
        printf("Ошибка ввода...");
    }
}

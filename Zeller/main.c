/***------------Calendar------------***/
/*This program is using Zeller formula to operate.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    /*First of all check if input is in the correct format (dd.mm.yyyy)*/
    if (argc != 2) {
        printf("Error. Invalid amount of arguments.\n");
        return -1;
    } else if (strlen(argv[1]) != 10){
        printf("Error. Invalid data format.\n");
        return -1;
    } else if (argv[1][2] != '.' || argv[1][5] != '.') {
        printf("Error. Invalid data format.\n");
        return -1;
    } else {
        int i;
        for (i = 0; i < 10; i++)
        {
            if(argv[1][i] != '.') {
                if(isdigit(argv[1][i]) == 0) {
                    printf("Error. Invalid data format.\n");
                    return -1;
                }
            }
        }
    }

    int day,month,year, century, result,ya_visocos;
    /*From char to int*/
    day = (argv[1][0] -'0') * 10 + (argv[1][1] - '0');
    month = (argv[1][3] - '0') * 10 + (argv[1][4] - '0');
    year = (argv[1][6] - '0') * 1000 + (argv[1][7] - '0') * 100 + (argv[1][8] - '0') * 10 + (argv[1][9] - '0');

    /*Check for leap year*/
    if (year % 4 == 0 || year % 400 == 0)
        ya_visocos = 1;
    else
        ya_visocos = 0;

    /*Check if input data is correct*/
    if (month > 12) {
        printf("Error. Invalid month.\n");
        return -1;
    } else if (year > 3999 || year < 1590) {
        printf("Error. Invalid year.\n");
        return -1;
    } else if (day > 31) {
        printf("Error. Invalid day.\n");
        return -1;
    } else {
        switch(month) {
            case 2:
                if ((ya_visocos = 1) && (day != 29))
                {
                    printf("Error. Invalid day.\n");
                    return -1;
                }
                else if ((ya_visocos != 0) && (day != 28))
                {
                    printf("Error. Invalid day.\n");
                    return -1;
                }
                break;
            case 3:
            case 4:
            case 6:
            case 9:
            case 11:
                if (day > 30)
                {
                    printf("Error. Invalid day.\n");
                    return -1;
                }
                break;
            default:
                if (day > 31)
                {
                    printf("Error. Invalid day.\n");
                    return -1;
                }
        }
    }

    /*Zeller formula in action*/
    if (month < 3)
    {
        month += 10;
        year--;
    } else
    {
        month -= 2;
    }

    century = year / 100;
    year = year % 100;

    result = (((26 * month - 2) / 10) + day + year + (year / 4) + (century / 4) - (2 * century)) % 7;

    if (result  < 0)
    {
        result += 7;
    }

    switch(result) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
    }

    return 1;
}

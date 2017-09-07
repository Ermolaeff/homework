int main(void)
{
    float count;
    char name;

    scanf("%f%*c%c", &count, &name);

    switch (name) {
    case 'C':
        printf("%.2f F\n%.2f K\n", count * 1.8 + 32, count + 273.15);
        getch();
        break;
    case 'F':
        printf("%.2f C\n%.2f K\n", (count - 32) / 1.8, (count + 459.67)*5/9);
        getch();
        break;
    case 'K':
        printf("%.2f C\n%.2f F\n", count + 273.15, count * 9/5-459.67);
        getch();

        break;
    default:
        printf("%.2f C:\n%.2f F\n%.2f K\n\n%.2f F:\n%.2f C\n%.2f K\n\n%.2f K:\n%.2f C\n%.2f F\n\n",
                count, count * 1.8 + 32, count + 273.15, count, (count - 32) / 1.8, (count + 459.67)*5/9,
                count, count + 273.15, count * 9/5-459.67);
        getch();
        break;
    }

    return 0;
}
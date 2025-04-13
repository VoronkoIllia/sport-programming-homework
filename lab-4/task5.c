#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    int number;

    while (1)
    {
        printf("Введіть тризначне число: ");
        scanf("%d", &number);
        if (number > 999 || number < 100)
        {
            printf("Число повинно бути тризначним! Спробуйте ще раз!\n");
        }
        else
        {
            break;
        }
    }

    int copy_of_number = number;
    int sum_of_digits = 0;
    for (int i = 0; i < 3; i++)
    {
        sum_of_digits += copy_of_number % 10;
        copy_of_number = (copy_of_number - copy_of_number % 10) / 10;
    }
    printf("Сума цифр числа %d дорівнює %d\n", number, sum_of_digits);
    return 0;
}
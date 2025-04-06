#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ua-UA");

    int number_1, number_2;

    printf("Введіть два цілих числа через пробіл: ");
    scanf("%d%d", &number_1, &number_2);

    if (number_1 > number_2)
    {
        printf("Більше число: %d", number_1);
    }
    else if (number_1 < number_2)
    {
        printf("Більше число: %d", number_2);
    }
    else
    {
        printf("Ці числа рівні");
    }
    return 0;
}
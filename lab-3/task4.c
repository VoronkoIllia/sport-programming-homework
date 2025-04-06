#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    int number;

    printf("Введіть ваше число: ");
    scanf("%d", &number);

    printf("Число %d є %s\n", number, number % 2 ? "непарним" : "парним");

    return 0;
}
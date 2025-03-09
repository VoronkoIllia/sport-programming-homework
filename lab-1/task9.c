#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ua-UA");
    int number;

    printf("Введіть ваше ціле число: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("Парне\n");
    }
    else
    {
        printf("Непарне\n");
    }
    return 0;
}
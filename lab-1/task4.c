#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    int integer;
    float rationalNumber;

    printf("Введіть ціле та дробове число через пробіл: ");
    scanf("%d %f", &integer, &rationalNumber);

    printf("Сума чисел: %f", integer + rationalNumber);

    return 0;
}
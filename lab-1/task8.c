#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ua-UA");
    float celsius_degrees, farenheit_degrees;
    printf("Введіть вашу температуру у градусах Цельсія: ");
    scanf("%f", &celsius_degrees);

    farenheit_degrees = celsius_degrees * 9 / 5 + 32;

    printf("Ваша температура у градусах Фаренгейта: %f", farenheit_degrees);
    return 0;
}
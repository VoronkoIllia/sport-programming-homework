#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    float meters;

    printf("Введіть довжину в метрах: ");
    scanf("%f", &meters);

    printf("Довжина в сантиметрах: %.1f см\n", meters * 100);
    printf("Довжина в міліметрах: %.1f мм\n", meters * 1000);

    return 0;
}
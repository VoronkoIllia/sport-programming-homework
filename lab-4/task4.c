#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    float cost;
    float discount;

    printf("Введіть ціну товару: ");
    scanf("%f", &cost);
    printf("Введіть знижку на товар відсотках: ");
    scanf("%f", &discount);

    discount /= 100;

    printf("Ціна на товар зі знижкою становить %.2f у. о.\n", cost * (1 - discount));

    return 0;
}
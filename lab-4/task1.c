#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    int cost = 450;
    float discount = 0.15;

    printf("Ціна гри без знижки: %d\n", cost);
    printf("Знижка: %.0f %%\n", discount * 100);
    printf("Ціна зі знижкою: %d\n", (int)(cost * (1.0 - discount)));

    return 0;
}
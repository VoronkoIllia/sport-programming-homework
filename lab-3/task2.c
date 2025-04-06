#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    const float PI = 3.14159265; // взяв з інтернету
    float radius;

    printf("Введіть радіус кола: ");
    scanf("%f", &radius);

    printf("Площа кола: %f кв. од.\n", PI * radius * radius);

    return 0;
}
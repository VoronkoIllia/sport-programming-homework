#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    double point1[2];
    double point2[2];
    int dimensionsCount;

    while (1)
    {
        printf("Введіть кількість вимірів у просторі: ");
        scanf("%d", &dimensionsCount);
        if (dimensionsCount < 2)
        {
            printf("Простір повинен мати мінімум 2 виміри! Спробуйте ще раз\n");
        }
        else
        {
            break;
        }
    }

    // створюємо масив с координатами для кожної точки
    double *point1_coordinates = (double *)calloc(dimensionsCount, sizeof(double));
    double *point2_coordinates = (double *)calloc(dimensionsCount, sizeof(double));

    // отримуємо координати кожної точки
    printf("Введіть координати першої точки: ");
    for (int i = 0; i < dimensionsCount; i++)
    {
        scanf("%lf", &point1_coordinates[i]);
    }

    printf("Введіть координати другої точки: ");
    for (int i = 0; i < dimensionsCount; i++)
    {
        scanf("%lf", &point2_coordinates[i]);
    }

    // обчислюємо відстань між точками
    double square_destination = 0.0;
    for (int i = 0; i < dimensionsCount; i++)
    {
        square_destination += pow(point2_coordinates[i] - point1_coordinates[i], 2);
    }
    double destination = sqrt(square_destination);

    // виводимо результати
    printf("\nВідстань між двома точками становить %f\n", destination);

    free(point1_coordinates);
    free(point2_coordinates);

    return 0;
}
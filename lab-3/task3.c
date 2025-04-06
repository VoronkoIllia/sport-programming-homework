#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    int totalTime;

    printf("Введіть час у секундах: ");
    scanf("%d", &totalTime);

    int seconds = totalTime % 60;
    totalTime = (totalTime - seconds) / 60; // тепер це кількість хвилин

    int minutes = totalTime % 60;
    totalTime = (totalTime - minutes) / 60; // тепер це кількість годин

    printf("Ваш час: %02d:%02d:%02d\n", totalTime, minutes, seconds);

    return 0;
}
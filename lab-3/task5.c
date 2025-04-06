#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    char letter;

    printf("Введіть малу латинську літеру: ");
    scanf("%c", &letter);

    printf("Велика літера \'%c\': %c", letter, letter - 32); // велика латинська літера менша від свого малого аналога на 32
    return 0;
}
#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    char character;

    printf("Введіть символ: ");
    scanf("%c", &character);

    printf("Наступний символ після \'%c\': %c", character, character + 1);

    return 0;
}
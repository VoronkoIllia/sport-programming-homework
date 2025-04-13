#include <stdio.h>
#include <time.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "ua-UA");

    // отримуємо поточний рік
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int current_year = current_time->tm_year + 1900;

    // зчитуємо рік народження користувача
    int user_birth_year;
    printf("Введіть ваш рік народження: ");
    scanf("%d", &user_birth_year);

    // обчислюємо кількість років користувача
    int user_age = current_year - user_birth_year;

    // задаємо правильну форму слова "рік"
    char *word_form;

    if (user_age % 10 == 1)
    {

        word_form = "рік";
    }
    else if (user_age % 10 > 1 && user_age % 10 < 5)
    {

        word_form = "роки";
    }
    else
    {

        word_form = "років";
    }

    // виводимо результати
    printf("Станом на %d рік вам було %d %s.\n", current_year, user_age, word_form);

    // очищуємо пам'ять
    free(word_form);
    return 0;
}
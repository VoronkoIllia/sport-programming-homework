#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// константи (знаю, що це директиви препроцесора, але тут вони грають роль констант)
#define CROSS 'X'   // символ хрестика
#define ZERO 'O'    // символ нулика
#define EMPTY ' '   // символ порожньої клітинки
#define CELL_SIZE 3 // розмір клітинки в символах, потрібен для вирівнювання по центру

// прототипи функцій
void resetBoard();
void drawBoard();
bool isBoardFull();
bool hasWon();

// глобальні змінні
char **board = NULL; // дошка для гри
int boardSize = 0;   // розмір дошки (на початку 0, тому що у нас на старті дошки по суті немає, потім буде введено користувачем)

int main()
{
    srand(time(NULL));                // робимо рандомайзер більш "рандомним"
    setlocale(LC_ALL, "ua_UA.UTF-8"); // встановлюємо українську локаль для коректного відображення символів

    while (true)
    {
        system("cls"); // очищаємо консоль

        // вводимо розмір дошки
        printf("\t\t \"Хрестики-нулики\"\n\n");
        printf("Введіть розмір дошки (мінімум 3): ");
        while (boardSize < 3)
        {
            scanf("%d", &boardSize);
            if (boardSize < 3)
            {
                printf("Розмір дошки має бути мінімум 3. Спробуйте ще раз: ");
            }
        }

        // створюємо дошку
        board = calloc(boardSize, sizeof(char *));
        for (int i = 0; i < boardSize; i++)
        {
            board[i] = calloc(boardSize, sizeof(char));
        }

        // робимо усі клітинки порожніми
        resetBoard();

        bool playerWon = false;                         // змінна-прапорець, що вказує, чи виграв гравець
        char currentPlayer = rand() % 2 ? CROSS : ZERO; // випадковий вибір гравця, який починатиме гру

        while (!isBoardFull())
        {
            system("cls"); // очищаємо консоль
            // виводимо дошку на екран
            drawBoard();

            // зчитуємо вибір гравця
            printf("Зараз ходить: %c\n", currentPlayer);
            printf("Введіть координати клітинки (рядок і стовпчик) через пробіл: ");

            int row, col;
            while (true)
            {
                scanf("%d %d", &row, &col);

                // користувачі не програмісти, тому рахуватимуть з одиниці, а не з нуля,
                // отже зменшуємо на 1, щоб перейти до індексації з 0
                row -= 1;
                col -= 1;

                // перевіряємо, чи введені координати коректні та чи є обрана клітинка вільною
                if (row < 0 || row >= boardSize || col < 0 || col >= boardSize || board[row][col] != EMPTY)
                {
                    printf("Некоректний хід. Спробуйте ще раз: ");
                }
                else
                {
                    break;
                }
            }

            // робимо хід
            board[row][col] = currentPlayer;

            // перевіряємо, чи виграв гравець
            // якщо виграв - завершуємо гру
            if (hasWon())
            {
                playerWon = true;
                break;
            }

            currentPlayer = currentPlayer == CROSS ? ZERO : CROSS; // змінюємо гравця
        }

        system("cls"); // очищаємо консоль
        drawBoard();   // виводимо останню версію дошки

        // виводимо результати гри
        if (playerWon)
        {
            printf("\nГру завершено! Гравець %c переміг!\n", currentPlayer);
        }
        else
        {
            printf("\nГру завершено в нічию!\n");
        }

        // звільняємо пам'ять
        for (int i = 0; i < boardSize; i++)
        {
            free(board[i]);
        }
        free(board);

        // питаємо, чи бажає користувач зіграти ще раз
        char answer;
        printf("Бажаєте зіграти ще раз? (y/n): ");
        scanf(" %c", &answer);

        if (answer != 'y')
        {
            break;
        }
        else
        {
            boardSize = 0; // скидаємо розмір дошки для наступної гри
            fflush(stdin); // очищаємо буфер вводу
        }
    }

    return 0;
}

// функція, що заповнює усі клітинки дошки пробілами
void resetBoard()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

// функція, що виводить дошку на екран
void drawBoard()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            printf("%*c%*c", CELL_SIZE / 2, ' ', -(CELL_SIZE / 2 + 1), board[i][j]);
            if (j != boardSize - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != boardSize - 1)
        {
            for (int k = 0; k < CELL_SIZE * boardSize + boardSize - 1; k++)
            {
                printf("-");
            }
            printf("\n");
        }
    }
}

// функція, що перевіряє, чи дошка заповнена
bool isBoardFull()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

// функція, що перевіряє, чи є на дошці перемога когось з гравців
bool hasWon()
{
    // перевірка рядків
    for (int i = 0; i < boardSize; i++)
    {
        bool checkRow = true;
        for (int j = 1; j < boardSize; j++)
        {
            if (board[i][j] != board[i][0] || board[i][0] == EMPTY)
            {
                checkRow = false;
                break;
            }
        }
        if (checkRow)
        {
            return true;
        }
    }

    // перевірка стовпчиків
    for (int j = 0; j < boardSize; j++)
    {
        bool checkCol = true;
        for (int i = 1; i < boardSize; i++)
        {
            if (board[i][j] != board[0][j] || board[0][j] == EMPTY)
            {
                checkCol = false;
                break;
            }
        }
        if (checkCol)
        {
            return true;
        }
    }

    // перевірка головної діагоналі
    bool checkMainDiag = true;
    for (int i = 1; i < boardSize; i++)
    {
        if (board[i][i] != board[0][0] || board[i][i] == EMPTY)
        {
            checkMainDiag = false;
            break;
        }
    }
    if (checkMainDiag)
    {
        return true;
    }

    // перевірка побічної діагоналі
    bool checkOtherDiag = true;
    for (int i = 1; i < boardSize; i++)
    {
        if (board[i][boardSize - 1 - i] != board[0][boardSize - 1] || board[i][boardSize - 1 - i] == EMPTY)
        {
            checkOtherDiag = false;
            break;
        }
    }

    return checkOtherDiag;
}
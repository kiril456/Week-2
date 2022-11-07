#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int res_index(int count_letters, int count_strings, int count_words);
int letters(char text[700]);
int strings(char text[700]);
int words(char text[700]);
void check(int res);

int main()
{
    char text[700];

    printf("Text: ");
    scanf("%[^\n]", text);

    int count_letters = letters(text);
    int count_strings = strings(text);
    int count_words = words(text);

    int res = res_index(count_letters, count_strings, count_words);

    check(res);
    return 0;
}
// Функція знаходить скільки букв
int letters(char text[700])
{
    int len = strlen(text);
    int count_letters = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters += 1;
        }
    }
    return count_letters;
}
// Функція знаходить скільки рядків
int strings(char text[700])
{
    int len = strlen(text);
    int count_strings = 0;

    for (int i = len; i > 0; i--)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count_strings += 1;
        }
    }
    return count_strings;
}
// Функція знаходить скільки слів
int words(char text[700])
{
    int len = strlen(text);
    int count_words = 1;

    for (int i = 1; i <= len; i++)
    {
        if (isspace(text[i]))
        {
            count_words += 1;
        }
    }
    return count_words;
}
// Вичисляє результат по формулі
int res_index(int count_letters, int count_strings, int count_words)
{
    float L = 0.0, S = 0.0;

    L = (float)count_letters / count_words * 100;
    S = (float)count_strings / count_words * 100;

    float num = 0.0588 * L - 0.296 * S - 15.8;
    int res = rint(num);

    return res;
}

void check(int res)
{
    if (res <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (res >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", res);
    }
}
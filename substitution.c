#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check(char argv[27], int argc);
void encryption(char key[30]);

int main(int argc, char *argv[])
{
    if (check(argv[argc - 1], argc) == 1)
    {
        return 1;
    }

    int a = check(argv[argc - 1], argc);

    return 0;
}

// the function checks whether the private key is valid
int check(char argv[27], int argc)
{
    int len = strlen(argv);
    int count = 0;

    if (argc == 1 || argc > 2)
    {
        count = 1;
        printf("Usage ./substitution key.\n");
    }
    else if (argc == 2)
    {
        if (len == 26)
        {
            for (int i = 0; i < len; i++)
            {
                if (isdigit(argv[i]) || ispunct(argv[i]))
                {
                    printf("Key must contain only alphabets\n");
                    count = 1;
                    break;
                }
                for (int j = i + 1; j < len; j++)
                {
                    if (toupper(argv[i]) == toupper(argv[j]) && argv[i] != ' ')
                    {
                        printf("Key must not contain repeated characters.\n");
                        count = 1;
                        break;
                    }
                }
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            count = 1;
        }
    }

    if (count == 0)
    {
        encryption(&argv[0]);
    }
    else
    {
        return 1;
    }
    return 0;
}

// function encrypts strings
void encryption(char key[30])
{
    int num;
    char letter, ciphertext[70], plaintext[70];

    printf("plaintext: ");
    scanf("%[^\n]", plaintext);

    int len = strlen(plaintext);

    for (int i = 0; i < len; i++)
    {
        letter = plaintext[i];
        if (ispunct(letter) || isspace(letter) || isdigit(letter))
        {
            ciphertext[i] = letter;
        }
        else
        {
            if (isupper(letter))
            {
                char str[2] = { letter };           // make a string out of the letter
                num = strtol(str, NULL, 36) - 10;   // convert the letter to a number
                ciphertext[i] = toupper(key[num]);
            }
            else
            {
                char str[2] = { letter };           // make a string out of the letter
                num = strtol(str, NULL, 36) - 10;   // convert the letter to a number
                ciphertext[i] = tolower(key[num]);
            }
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}
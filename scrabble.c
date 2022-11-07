#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void compare(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    compare(score1, score2);
}

int compute_score(string word)
{
    int score = 0, num = 0;
    int len = strlen(word);
    char letter;

    for (int i = 0; i < len; i++)
    {
        letter = word[i];
        if (ispunct(letter) == 0)
        {
            char str[2] = { letter };           // make a string out of the letter
            num = strtol(str, NULL, 36) - 10;   // convert the letter to a number
            score += POINTS[num];               
        }
        else
        {
            score += 0;
        }
    }
    return score;
}

void compare(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
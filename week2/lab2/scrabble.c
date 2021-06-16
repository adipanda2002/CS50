// A programme that allows two players to determine which of their words would receive a higher score in the game of scrabble

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet in Scrabble
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Prints the winner
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

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;
    
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
          // if a given letter of the word is capitalized, its respective ASCII number is used to determine its index in the POINTS array.
          // this index can be used to assign the correct number of points for the use of that letter
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
          // Similarly, ASCII number differences are used to determine an index number on the POINTS array and score lowercase letters used
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    
    return score;
}

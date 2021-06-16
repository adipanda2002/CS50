// A programme that determines the complexity of text inputed by the user

//includes
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: "); // receive user input text
    int number_of_letters, number_of_words, number_of_sentences;
    number_of_letters = number_of_words = number_of_sentences = 0; // sets variables for no. of letters, words and sentences to 0
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            number_of_letters++; // increases the letter number count by 1 each time an alphabet is detected by the islpha function 
        }
        if ((i == 0 && text[i] != ' ') || (i != len - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            number_of_words++; // uses the knowledge that there are spaces between words to determine how many words are present in the input text
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            number_of_sentences++; // every time a sentence is ended (with a '.', '?' or '!'), the sentence count is increased by 1
        }
    }
    float L = (number_of_letters / (float) number_of_words) * 100;
    float S = (number_of_sentences / (float) number_of_words) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8); //Coleman-Liau index is determined with this formula
        
    // print the grade level of the inputed text as per pre-defined ranges
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index); 
    }
}

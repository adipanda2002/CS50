// A programme to predict population changes with known birth and death rates

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompts user for start size
    
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    //Prompts user for end size
    
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    
    //Calculates number of years until we reach threshold
    
    int years = 0;
    
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", years);
}

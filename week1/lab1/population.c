// A programme to predict population changes with known birth and death rates

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for start size
    
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    
    // Prompt user for end size
    
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    
    // Calculate number of years until we reach threshold
    
    int years = 0;
    
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }
    
    // Print number of years
    printf("Years: %i\n", years);
}

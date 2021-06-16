/*This is a programme that allows the user to select the height of a pyramid in a Mario obstacle course*/ 

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    
    do
    {
        n = get_int("Please select a height (1-8).\n");
        // prompts the user for a pyramid height
    }
    while (n < 1 || n > 8);
    
    // Using a for loop to print each row of the desired pyramind
    for (i = 0; i < n; i++)
    {
        printf(' ', n - 1 - i);
        printf('#', i + 1);
        printf(' ', 2);
        printf('#', i + 1);
    }
    
    printf('\n');
    

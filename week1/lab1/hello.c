/*A programme that allows the computer to ask for the user's name and say hello*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s!\n", name);
}

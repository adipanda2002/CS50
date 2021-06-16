//includes
#include <stdio.h>
#include <cs50.h>

//functions
bool VALIDATE(long long n);
int LENGTH(long long n);
bool CHECKSUM(long long n);
void PRINTBRAND(long long n);

int main(void)
{
    long long n; // Where n is a variable for credit card number
    
    do
    {
        n = get_long_long("Number: ");
        // Receives input from user
    }
    while (n < 0);
    
    if (VALIDATE(n) == true)
    {
        PRINTBRAND(n);
        // If number is valid, credit card brand is printed
    }
    else
    {
        printf("INVALID\n");
        // For invalid inputs
    }
}

bool VALIDATE(long long n)
{
    int len = LENGTH(n);
    return ((len == 13 || len == 15 || len == 16) && CHECKSUM(n));
    // Checks for correct number of digits and Luhn's Algorithm
}

int LENGTH(long long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

bool CHECKSUM(long long n) // Function for Luhn's Algorithm
{
    int sum = 0;
    for (int i = 0; n != 0; i++, n /= 10)
    {
        if (i % 2 == 0)
        {
            sum += n % 10;
        }
        else
        {
            int digit = 2 * (n % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

void PRINTBRAND(long long n) // Print instructions based on starting digits
{
    if ((n >= 34e13 && n < 35e13) || (n >= 37e13 && n < 38e13))
    {
        printf("AMEX\n");
    }
    else if ((n >= 51e14 && n < 56e14))
    {
        printf("MASTERCARD\n");
    }
    else if ((n >= 4e12 && n < 5e12) || (n >= 4e15 && n < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
  

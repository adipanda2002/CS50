// A progamme to encrypt a message inputed by the user

// Usage:./substitution [KEY]

// [KEY] = a 26 character input that serves as a reference for encrypting alphabet input


//includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool key_validation(string s); //function to validate key

int main(int argc, string argv[])
{
    if (argc != 2) // in the case that the user does not input a key in the command line
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!key_validation(argv[1])) //for keys that fail required conditions
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    
    string s = get_string("plaintext: ");
    string diff = argv[1];
    for (int i = 'A'; i <= 'Z'; i++) //maps alphabets to correspoding indices on the key
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i;
    }
    printf("ciphertext: ");
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            s[i] = s[i] + diff[s[i] - (isupper(s[i]) ? 'A' : 'a')];
        }
        printf("%c", s[i]);
    }
    printf("\n");
}

bool key_validation(string s) //function to validate key
{
    int len = strlen(s);
    if (len != 26) //checks that key length is 26 characters
    {
        return false;
    }
    
    int freq[26] = { 0 }; // checks for no repeat characters
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
        int index = toupper(s[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }
    
    return true;
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



string cipher(string key, string text);

int main(int argc, string argv[])
{
    bool valid = false;
    if (argc == 2)
    {
        string key = argv[1];
        int keylenght = strlen(key);
        if (keylenght != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            for (int i = 0 ; i < keylenght ; i++)
            {
                char c = key[i];
                if (isalpha(c) == 0)
                {
                    printf("Key must contain only alphabetical characters.\n");
                    return 1;
                    break;
                }
                else
                {
                    key[i] = tolower(c);
                }
            }
            for (int j = 0 ; j < keylenght-1 ; j++)
            {
                for (int k = j + 1 ; k < keylenght ; k++)
                {
                    if ((int)key[j] == (int)key[k])
                    {
                        printf("The key isnt allowed to have duplicate letters\n");
                        return 1;
                        break;
                    }
                }
            }
            string plaintext = get_string("plaintext: ");
            string ciphertext = cipher(key, plaintext);
            printf("ciphertext: %s\n",ciphertext);
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
string cipher(string key, string text)
{
    char cychar;
    int lenght = strlen(text);
    for (int i = 0; i < lenght ; i++)
    {
        cychar = tolower(text[i]);
        if (isalpha(cychar) != 0)
        {
            int ichar = cychar - 97;
            cychar = key[ichar];
            if (isupper(text[i]) != 0)
            {
                cychar = toupper(cychar);
            }
        }
        text[i] = cychar;
    }
    return text;
}
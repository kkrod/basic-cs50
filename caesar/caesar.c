#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(int key, string text);

int main(int argc, string argv[])
{
    bool valid = false;
    if (argc == 2)
    {
        valid = true;
        string key = argv[1];
        int keylenght = strlen(key);
        for (int i = 0 ; i < keylenght ; i++)
        {
            char c = key[i];
            if (isdigit(c) == 0)
            {
                valid = false;
            }
        }
        if (valid)
        {
            int ikey = atoi(key);
            string plaintext = get_string("plaintext: ");
            string ciphertext = cipher(ikey, plaintext);
            printf("ciphertext: %s\n",ciphertext);
        }
        
    }
    if (valid != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
string cipher(int key, string text)
{
    char cychar;
    int lenght = strlen(text);
    key = key % 26;
    for (int i = 0; i < lenght ; i++)
    {
        cychar = text[i];
        if (isalpha(cychar) != 0)
        {
            cychar = cychar + key;
            if ((isupper(text[i]) == 0 && isupper(cychar) != 0) || (isalpha(cychar) == 0))
            {
                cychar = cychar - 26;
            }
        }
        text[i] = cychar;
    }
    return text;
}
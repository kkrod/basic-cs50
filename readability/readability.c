#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_sentences(string letters);
int count_letters(string letters);
int count_words(string letters);

int main(void)

{
    string text = get_string("Text: ");
    int count = count_letters(text);
    int c_words = count_words(text);
    int c_sentences = count_sentences(text);
    float l, s;
    l = count / (float) c_words * 100;
    s = c_sentences / (float) c_words * 100;
    int i =  round(0.0588 * l - 0.296 * s - 15.8);
    printf("%i || %i || %i", count, c_words, c_sentences);
    printf("%0.2f || %0.2f || %i", l, s, i);
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (i > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}
int count_letters(string letters)
{
    int s = strlen(letters);
    char character;
    int contador = 0;
    for (int i = 0; i < s ; i++)
    {
        character = letters[i];
        if ((character > 64 && character < 91) || (character >= 97 && character <= 122))
        {
            contador++;
        }
    }
    return contador;
}
int count_sentences(string letters)
{
    int s = strlen(letters);
    char character;
    int contador = 0;
    for (int i = 0; i < s ; i++)
    {
        character = letters[i];
        if (character == 33 || character == 46  || character == 63)
        {
            contador++;
        }
    }
    return contador;

}
int count_words(string letters)
{
    int s = strlen(letters);
    char character;
    int contador = 1;
    for (int i = 0; i < s ; i++)
    {
        character = letters[i];
        if (character == 32)
        {
            contador++;
        }
    }
    return contador;
}